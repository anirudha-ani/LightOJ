//
//  main.c
//  10071 - Back to High School Physics
//
//  Created by Anirudha on 5/16/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a,b,c;
    
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        c=2*a*b;
        printf("%d\n",c);
    }
    return 0;
    
}
