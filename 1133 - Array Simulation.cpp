#include <cstdio>
#include <iostream>

using namespace std;

int array[105];
int main()
{
    int T , n , m , element , X , Y;
    char command;
    int temp ;
    int index;

    scanf("%d", &T);
    //cout << T << endl;
    for(int  i = 0 ; i < T ; i++)
    {
        scanf("%d %d", &n , &m);
        //cout << n << "::" << m << endl;

        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &array[j]);
        }
//        for(int j = 0 ; j < n ; j++)
//        {
//            printf("%d ", array[j]);
//        }
        //cout << endl;

        for(int j = 0 ; j < m ; j++)
        {
            cin >> command;
            //cout << command << endl;
            switch(command)
            {
                case 'S':
                    scanf("%d", &element);
                    for(int k = 0 ; k < n ; k++)
                    {
                        array[k] += element;
                    }
                    break;

                case 'M':
                    scanf("%d", &element);
                    for(int k = 0 ; k < n ; k++)
                    {
                        array[k] *= element;
                    }
                    break;

                case 'D':
                    scanf("%d", &element);
                    for(int k = 0 ; k < n ; k++)
                    {
                        array[k] /= element;
                    }
                    break;

                case 'R':
                    index = n-1;
                    for(int k = 0 ; k < n/2 ; k++)
                    {
                        temp = array[k];
                        array[k] = array[index];
                        array[index] = temp;
                        index--;
                    }
                    break;

                case 'P':
                    scanf("%d %d", &X , &Y);
                    temp = array[X];
                    array[X] = array[Y];
                    array[Y] = temp;
                    break;
            }
        }
        printf("Case %d:\n", i+1);
        for(int k = 0; k < n ; k++)
        {
            printf("%d", array[k]);
            if(k==n-1)
            printf("\n");
            else
            printf(" ");
        }
    }
    return 0;
}
