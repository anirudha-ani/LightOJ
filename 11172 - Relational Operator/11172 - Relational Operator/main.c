//
//  main.c
//  11172 - Relational Operator
//
//  Created by Anirudha on 5/16/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a,b,c ;
    scanf("%d",&c);
    
    while (c!=0)
    {
        scanf("%d %d",&a,&b);
        
        if(a>b)
            printf("%c\n",'>');
        else if (a<b)
            printf("%c\n",'<');
        else
            printf("%c\n",'=');
        c--;
    }
}
