//Problem Link - http://lightoj.com/volume_showproblem.php?problem=1005

#include <bits/stdc++.h>

using namespace std ;
int T , n , k;
long long int DP[35][35][1000];
long long int calculate(int row_available , int column_available , int remaining)
{
    if(remaining > row_available || remaining > column_available)
    {
        return 0;
    }
    else if(remaining == 0)
    {
        return 1 ;
    }
    else if(row_available == 1)
    {
        return column_available;
    }
    else if(DP[row_available][column_available][remaining] != -1)
    {
        return DP[row_available][column_available][remaining];
    }
    else
    {
        return column_available * calculate(row_available-1 , column_available -1 , remaining -1 ) + calculate(row_available-1 , column_available , remaining);
    }

}
int main()
{


    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        memset(DP , -1 , sizeof(DP));

        scanf("%d %d", &n , &k);

        printf("Case %d: %lld\n",i+1, calculate(n , n , k));
    }
    return 0 ;
}
