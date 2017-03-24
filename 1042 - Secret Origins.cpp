#include <cstdio>
#include <iostream>

using namespace std;
int power(int x , int y)
{
    int result = 1;

    for(int i = 0 ; i < y ; i++)
    {
        result *= x;
    }
    return result;
}
int main()
{
    int T , N , count_one , position , output;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d",&N);

        count_one = 0;

        int index  = 0;

        position=(N&(-N));



        while((N & position)  != 0)
        {
            position *=2;
        }
        N += (position/2);

        int change_position = position;
        while(change_position!=(N&(-N)))
        {
            //cout << "Activated"<< endl;
            position=(N&(-N));
            N -= position;
            count_one++;
        }

        N += power(2, count_one);



        printf("Case %d: %d\n", i+1 , N-1);
    }
    return 0;
}
