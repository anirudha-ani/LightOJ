//
//  main.c
//  1008 - Fibsieve`s Fantabulous Birthday
//
//  Created by Anirudha on 5/12/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>

int main()
{
    int T ,row , column;
    double S;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%lf" , &S);

        if(S == 1)
        {
            printf("Case %d: 1 1\n",i+1);
            continue;
        }

        int positioning = (int)ceil(sqrt(S));
        int origin = positioning * positioning;

        if(positioning % 2 == 0)
        {
            column = positioning ;
            row = 1 ;
        }
        else
        {
            column = 1 ;
            row = positioning ;
        }

        if(S == origin)
        {
            printf("Case %d: %d %d\n", i+1 , row , column);
            continue;
        }
        else
        {
            if(S>= (origin - positioning))
            {
                if(row == 1)
                    row = row + orign - S;
                else if (column == 1)
                    column = column + origin - S;
            }
            else
            {
                if(row == 1)
                {
                    row = positioning;
                    column = positioning - (origin - positioning - S);
                }
                else if (column == 1)
                {
                    column = positioning;
                    row =  positioning - (origin - positioning - S);
                }
            }
        }
        printf("Case %d: %d %d\n", i+1 , row , column);
    }
    return 0 ;

}
