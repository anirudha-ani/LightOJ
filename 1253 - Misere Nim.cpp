#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int T ;
    int pile_number;
    int xorValue;
    int value;

    scanf("%d", &T);


    for(int i = 0 ; i < T ; i++)
    {
        xorValue = 0 ;
        scanf("%d", &pile_number);
        bool found = false;
        for(int j = 0 ; j < pile_number ; j++)
        {
            scanf("%d", &value);
            if(value != 1)
            {
                found = true;
            }
            xorValue = xorValue ^ value;
        }
        if(found)
        {
             if(xorValue == 0)
            {
                printf("Case %d: Bob\n", i+1);
            }
            else
            {
                printf("Case %d: Alice\n", i+1);
            }
        }
        else
        {
            if(pile_number%2 == 0)
            {
                printf("Case %d: Alice\n", i+1);
            }
            else
            {
                printf("Case %d: Bob\n", i+1);
            }
        }

    }
    return 0;
}
