//
//  main.c
//  10812 - Beat the Spread!
//
//  Created by Anirudha on 5/16/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include<stdio.h>
int main()
{
    int a,b,x,y,i=1,j;
    scanf("%d",&j);
    while (i<=j)
    {
        scanf("%d %d",&a,&b);
        if (a>=b&&(a+b)%2==0)
        {
            x=(a+b)/2;
            y=(a-b)/2;
            printf("%d %d\n",x,y);
        }
        else
            printf("impossible\n");
        i++;
    }
    return 0;
}

