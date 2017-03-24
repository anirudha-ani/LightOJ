#include <bits/stdc++.h>

using namespace std;

int grudyNumber[10005];
int grundy[10005];

int main()
{
    int T;
    memset(grudyNumber , -1 , sizeof(grudyNumber));

    grudyNumber[0] = 0;
    grudyNumber[1] = 0;
    grudyNumber[2] = 0;

    for(int i = 3 ; i < 10005 ; i++)
    {
        int j = 1 ;
        int k = i-1;
        memset(grundy , 0 , sizeof(grundy));


        for( ; j<k ; j++ , k--)
        {
            grundy[grudyNumber[j] ^ grudyNumber[k]] = 1;
        }

        int m = 0 ;
        while(grundy[m] !=0)
        {
            m++;
        }
        grudyNumber[i] = m;
    }

    scanf("%d" , &T);

    int n , input , xorValue ;
    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d", &n);
        xorValue = 0;
        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d" , &input);
            xorValue ^= grudyNumber[input];
        }
        if(xorValue != 0)
        {
            printf("Case %d: Alice\n", i+1);
        }
        else
        {
             printf("Case %d: Bob\n", i+1);
        }
    }
    return 0;
}
