#include <cstdio>

using namespace std;

int main()
{
    int T,input , count_one;

    scanf("%d", &T);

    for(int i = 0 ; i < T ;i++)
    {
        count_one = 0;

        scanf("%d", &input);

        while(input != 0)
        {
            input -= ((input) & (-input));
            count_one++;
        }
        if(count_one % 2 != 0)
        {
            printf("Case %d: odd\n", i+1);
        }
        else
        {
            printf("Case %d: even\n", i+1);
        }
    }
    return 0;
}
