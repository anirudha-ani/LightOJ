//
//  main.c
//  1015 - Brush (I)
//
//  Created by Anirudha on 5/28/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a,b,c,d=1,sum;
    
    scanf("%d",&a);
    
    while (a>0)
    {
        sum=0;
        scanf("%d",&b);
        while(b>0)
        {
            scanf("%d",&c);
            if(c<0)
            {
                c=0;
            }
            sum=sum+c;
            b--;
        }
        printf("Case %d: %d\n",d,sum);
        d++;
        a--;
    }
    
}
