#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector <double> digitsOfFactorialInBaseTen;

int main()
{
    digitsOfFactorialInBaseTen.push_back(0.0);
    digitsOfFactorialInBaseTen.push_back(0.0);
    for(int i = 2 ; i < 1000001 ; i++)
    {
        digitsOfFactorialInBaseTen.push_back(digitsOfFactorialInBaseTen[i-1] + log10(i));
    }

    int T , n , base , ans ;

    scanf("%d", &T);

    for(int i = 0; i < T ; i++)
    {
        scanf("%d %d", &n , &base);
        ans = digitsOfFactorialInBaseTen[n] / log10(base);
        ans += 1;
        printf("Case %d: %d\n",i+1, ans);
    }
    return 0;
}
