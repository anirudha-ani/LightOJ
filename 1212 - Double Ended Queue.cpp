#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int doubleQueue[300];
int main()
{
    int T , n , m , leftIndex , rightIndex , totalItem , x;
    string command;

    scanf("%d", &T);

    for(int i = 0 ; i < T ;i++)
    {
        leftIndex = 150;
        rightIndex = 151;
        totalItem = 0;
        scanf("%d %d", &n , &m);
        printf("Case %d:\n",i+1);
        for(int j = 0 ; j < m ; j++)
        {
            cin >> command;
            //cout <<"J= " << j+1 <<": "<< command << endl;
            if(command == "pushLeft")
            {

                scanf("%d", &x);
                if(totalItem != n)
                {
                    doubleQueue[leftIndex] = x;
                    leftIndex--;
                    printf("Pushed in left: %d\n",x);
                    totalItem ++;
                }
                else
                {
                    printf("The queue is full\n");
                }

            }
            else if(command == "pushRight")
            {
                scanf("%d", &x);
                if(totalItem != n)
                {
                    doubleQueue[rightIndex] = x;
                    rightIndex++;
                    printf("Pushed in right: %d\n",x);

                    totalItem++;
                }
                else
                {
                    printf("The queue is full\n");
                }

            }
            else if(command == "popLeft")
            {
                if(totalItem != 0)
                {
                    leftIndex++;
                    printf("Popped from left: %d\n",doubleQueue[leftIndex]);
                    totalItem--;
                }
                else
                {
                    printf("The queue is empty\n");
                }
            }
            else if(command == "popRight")
            {
                if(totalItem != 0)
                {
                    rightIndex--;
                    printf("Popped from right: %d\n",doubleQueue[rightIndex]);
                    totalItem--;
                }
                else
                {
                    printf("The queue is empty\n");
                }
            }
        }
    }
    return 0;
}
