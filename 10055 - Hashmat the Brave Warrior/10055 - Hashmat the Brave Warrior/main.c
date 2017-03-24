//
//  main.c
//  10055 - Hashmat the Brave Warrior
//
//  Created by Anirudha on 5/16/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include<stdio.h>
int main()
{
    long long int a,b,c;
    while(scanf("%lld%lld",&a,&b)==2)
    {
        if(a>b)
            c=a-b;
        else
            c=b-a;
        printf("%lld\n",c);
    }
    return 0;
}
