//
//  main.c
//  1205 - Palindromic Numbers
//
//  Created by Anirudha on 5/21/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>


int main()
{
    int a,x,y,b,rev,count,temp,num;
    num=1;
    scanf("%d",&a);
    while (a!=0)
    {
        count=0;
        scanf("%d %d",&x,&y);
        if(x>y)
        {
            temp=x;
            x=y;
            y=temp;
        }
        while (x<=y)
        {
            b=x;
            rev=0;
            while (b!=0)
            {
                rev=rev*10;
                rev=rev+b%10;
                b=b/10;
            }
            if (x-rev==0)
            {
                count++;
            }
            x++;
           
        
        }
        printf("Case #%d: %d\n",num,count);
        num++;
    }
}

