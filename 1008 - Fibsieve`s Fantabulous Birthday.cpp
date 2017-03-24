#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    long long int T ,row , column ,S ,root ,remaining;


    scanf("%lld", &T);

    for(long long int i = 0 ; i < T ; i++)
    {
        scanf("%lld" , &S);

        root = floor(sqrt(S));

        if(root%2 == 0)
        {
            row = 1;
            column = root;
        }
        else
        {
            row = root ;
            column = 1;
            //cout << column <<"::" << row <<endl;
        }

        remaining = S - (root * root);


            if(row == 1 && remaining != 0 && column !=1)
            {
                column += 1;
                remaining--;
                //cout << column <<"::" << row <<endl;
                if(remaining != 0)
                {
                    if(remaining <= (column-1))
                    {
                        row+= remaining;
                        remaining = 0;
                        //cout << column <<"::" << row <<endl;
                    }
                    else
                    {
                        row += (column-1) ;
                        //cout << column <<"::" << row <<endl;
                        remaining -= (column-1);
                        column -= remaining;
                        //cout << column <<"::" << row <<endl;
                    }
                }
            }


            else if(column == 1 && remaining != 0)
            {
                row += 1;
                remaining--;
                //cout << column <<"::" << row <<endl;
                if(remaining != 0)
                {
                    if(remaining <= (row-1))
                    {
                        column+= remaining;
                        remaining = 0;
                        //cout << column <<"::" << row <<endl;
                    }
                    else
                    {
                        column += (row-1) ;
                        //cout << column <<"::" << row <<endl;
                        remaining -= (row-1);
                        row -= remaining;
                        //cout << column <<"::" << row <<endl;
                    }
                }
            }

            printf("Case %lld: %lld %lld\n", i+1 , column , row);

    }
    return 0 ;

}

