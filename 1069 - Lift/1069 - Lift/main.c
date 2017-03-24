//
//  main.c
//  1069 - Lift
//
//  Created by Anirudha on 5/30/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>

int main()
{
    int case_no, no=1;
    int you,lift,time;
    
    scanf("%d",&case_no);
    while (no<=case_no)
    {
        scanf("%d %d",&you,&lift);
        if(lift>=you)
        {
            time=lift*4+19;
        }
        else
        {
            time=(you-lift)*4+you*4+19;
        }
        printf("Case %d: %d\n",no,time);
        no++;
    }
}