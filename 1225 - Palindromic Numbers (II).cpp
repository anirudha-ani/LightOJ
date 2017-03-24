#include <cstdio>

using namespace std;

int main()
{
    int T, input,lost_in_devide ,input_reverse;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d", &input);
        input_reverse = 0;

        lost_in_devide = input;
        while(lost_in_devide>9)
        {
            input_reverse = input_reverse*10+lost_in_devide%10;
            lost_in_devide /= 10;
        }
        input_reverse = input_reverse*10+lost_in_devide;
        if(input_reverse == input )
            printf("Case %d: Yes\n",i+1);
        else
            printf("Case %d: No\n",i+1);
    }
    return 0;
}
