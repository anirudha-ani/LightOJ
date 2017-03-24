#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;



int main()
{
    int T , n , p , q , weight , total_weight , answer;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        total_weight = 0;
        answer = 0;

        scanf("%d %d %d", &n , &p , &q);

        for(int j = 1 ; j <= n ; j++)
        {
            scanf("%d", &weight);
            if(total_weight + weight <= q && answer + 1 <=p)
            {
                answer++;
                total_weight += weight;
            }
        }

        printf("Case %d: %d\n",i+1, answer);
    }
    return 0;
}
