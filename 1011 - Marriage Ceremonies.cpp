
#include <bits/stdc++.h>

using namespace std ;

int T , n ;
int DP[20][131075];

int info[20][20];

int calculate(int person , int taken)
{
    if(DP[person][taken] != -1)
    {
        return DP[person][taken];
    }
    //cout << person << "::" << taken << endl ;
    if(person == n-1)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(taken & (1 << i) == 0)
            {
                return info[person][i];
            }
        }
    }
    int maxi = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        //cout << (taken & (1 << i ) )<< endl ;
        if( (taken & (1 << i)) == 0)
        {
            //cout  << person << "::" << taken << endl ;
            int return_value = calculate(person+1 , taken | (1 << i));

            if(info[person][i] + return_value > maxi)
            {
                maxi = info[person][i] + return_value ;
            }
        }
    }
    DP[person][taken] = maxi ;
    return maxi ;

}

int main()
{


    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        memset(DP , -1 , sizeof(DP));
        scanf("%d", &n);

        for(int j = 0 ; j < n ; j++)
        {
            for(int k = 0 ; k < n ; k++)
            {
                scanf("%d", &info[j][k]);
            }
        }

        int ans = calculate(0,0);
        printf("Case %d: %d\n", i+1 , ans );
    }


    return 0 ;
}
