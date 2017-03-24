//
//  main.c
//  1107 - How Cow
//
//  Created by Anirudha on 5/30/14.
//  Copyright (c) 2014 Anirudha Paul. All rights reserved.
//

#include <stdio.h>

int main()
{
    int case_no,no=1;
    int x1,y1,x2,y2,cow;
    int x,y;
    
    scanf("%d",&case_no);
    
    while (no<=case_no)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        
        scanf("%d",&cow);
        printf("Case %d:\n",no);
    
        while (cow!=0)
        {
            scanf("%d %d",&x,&y);
            if (x>=x1&&x<=x2&&y>=y1&&y<=y2)
            {
                printf("Yes\n");
            }
            else
                printf("No\n");
            cow--;
        }
        no++;
    }
}