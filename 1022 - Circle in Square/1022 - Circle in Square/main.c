//
//  main.c
//  1022 - Circle in Square
//
//  Created by Anirudha on 5/28/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main ()
{
    int case_num, i;
    double pi = 2 * acos (0.0);
    scanf("%d", &case_num);
    for (i=1;i<=case_num;i++)
    {
        double r;
        scanf("%lf",&r);
        double a, b;
        a=pi*r*r;
        b= 4*r*r;
        printf("Case %d: %.2f\n",i,b-a);
    }
    return 0;
}