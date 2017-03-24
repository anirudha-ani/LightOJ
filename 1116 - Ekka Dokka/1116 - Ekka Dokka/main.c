//
//  main.c
//  1116 - Ekka Dokka
//
//  Created by Anirudha on 5/30/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>

int main()
{
    int case_no,no=1;
    int dash,ekka=0,dokka=2,a,b=1;
    
    scanf("%d",&case_no);
    
    
    while (no<=case_no)
    {
        ekka=0;
        dokka=2;
        b=1;
        scanf("%d",&dash);
        
        while(b!=0)
        {
            a=dash/dokka;
            if (a%2!=0 && (a*dokka)==dash)
            {
                ekka=a;
                printf("Case %d: %d %d\n",no,ekka,dokka);
                b=0;
            }
            else if (dokka>=(dash/2))
            {
                printf("Case %d: Impossible\n",no);
                b=0;
            }
            dokka=dokka+2;
        }
        
        no++;
    }
}