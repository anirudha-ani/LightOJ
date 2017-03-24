//
//  main.c
//  1053 - Higher Math
//
//  Created by Anirudha on 5/30/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>

int main()
{
    int case_no,a,b,c,no=1;
    
    scanf("%d",&case_no);
    
    while (case_no>0)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a>b&&a>c)
        {
            if (a*a==b*b+c*c)
            {
                printf("Case %d: yes\n",no);
            }
            else printf("Case %d: no\n",no);
        }
        if(b>a&&b>c)
        {
            if (b*b==a*a+c*c)
            {
                printf("Case %d: yes\n",no);
            }
            else printf("Case %d: no\n",no);
        }

        if(c>a&&c>b)
        {
            if (c*c==b*b+a*a)
            {
                printf("Case %d: yes\n",no);
            }
            else printf("Case %d: no\n",no);
        }
        no++;
        case_no--;

    }
}
