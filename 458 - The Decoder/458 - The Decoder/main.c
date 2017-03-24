//
//  main.c
//  458 - The Decoder
//
//  Created by Anirudha on 5/14/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000000];
    while(gets(a))
    {
    int i=0;
    
    while(a[i])
    {
        a[i]=a[i]-7;
        i++;
    }
    
    puts(a);
    }
}

