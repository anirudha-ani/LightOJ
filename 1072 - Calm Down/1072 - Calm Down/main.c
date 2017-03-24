//
//  main.c
//  1072 - Calm Down
//
//  Created by Anirudha on 5/30/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979

int main()
{
    int cases, caseNo;
    scanf("%d",&cases);
    
    for(caseNo = 0; caseNo < cases; caseNo++)
    {
        double big_radius, small_radius, sides;
        scanf("%lf",&big_radius);
        scanf("%lf", &sides);
        
        small_radius = (big_radius * sin((180.0 * PI / 180.0)/sides)) / (1 + sin((180.0 * PI / 180.0)/sides));
        
        printf("Case %d: %.10lf\n", caseNo+1, small_radius);
    }
    return 0;
}

