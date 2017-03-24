//
//  main.cpp
//  1202 - Bishops
//
//  Created by Anirudha Paul on 1/14/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int T , r1 , c1 , r2 , c2;
    
    scanf("%d" , &T);
    
    for(int i = 0 ; i < T; i++)
    {
        scanf("%d %d %d %d", &r1 , &c1 , &r2 , &c2);
        
        if(((r1 % 2 == 0 && c1%2 == 0)||(r1%2 == 1 && c1 %2 ==1))&&((r2 % 2 == 0 && c2%2 == 0)||(r2%2 == 1 && c2 %2 ==1)))
        {
            if (abs(r1-r2) == abs(c1-c2))
            {
                printf("Case %d: 1\n",i+1);
            }
            else
            {
                printf("Case %d: 2\n",i+1);
            }
        }
        else if(((r1 % 2 == 0 && c1%2 == 1)||(r1%2 == 1 && c1 %2 ==0))&&((r2 % 2 == 0 && c2%2 == 1)||(r2%2 == 1 && c2 %2 ==0)))
        {
            if (abs(r1-r2) == abs(c1-c2))
            {
                printf("Case %d: 1\n",i+1);
            }
            else
            {
                printf("Case %d: 2\n",i+1);
            }

        }
        else
        {
            printf("Case %d: impossible\n",i+1);
        }
    }
    return 0;
}
