//
//  main.cpp
//  1012 - Guilty Prince
//
//  Created by Anirudha Paul on 5/19/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string> 

using namespace std;

int destination_no(bool flag [][20],char input[][20], int x_axis , int y_axis , int akbar_x , int akbar_y );

int main(int argc, const char * argv[])
{
    char input[20][20];
    
    int input_no = 0;
    
    int x_axis = 0;
    int y_axis = 0;
    
    int akbar_x = 0;
    int akbar_y = 0;
    
    scanf("%d" , &input_no);
    
    for(int i = 0 ; i < input_no ; i++)
    {
        bool flag [20][20];
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0 ; j < 20 ; j++)
            {
                flag[i][j]=false;
            }
        }
        scanf("%d %d" , &x_axis , &y_axis);
        
        string fake;
        cin.clear();
        getline(cin, fake);
        
        for (int j = 0 ; j < y_axis; j++)
        {
            string line;
            cin.clear();
            getline(cin, line);
            
            for (int k = 0 ; k < x_axis; k++)
            {
                if (line[k] == '@')
                {
                    akbar_x = k ;
                    akbar_y = j;
                }
                input[k][j] = line[k];
            }
        }
         destination_no(flag ,input, x_axis, y_axis , akbar_x , akbar_y);
        int count = 0 ;
        for (int i = 0; i <x_axis; i++)
        {
            for (int j = 0 ; j < y_axis ; j++)
            {
                if (flag[i][j] == true)
                {
                    count++;
                }
            }
        }
        
        printf("Case %d: %d\n" , i+1 , count);
        
    }
    
    
    return 0;
}

int destination_no(bool flag[][20], char input[][20], int x_axis , int y_axis , int akbar_x ,int akbar_y)
{
    
    flag[akbar_x][akbar_y] = true;
    
    if (input[akbar_x-1][akbar_y] != '#' && akbar_x-1 >=0 && akbar_y >=0 && akbar_x-1 < x_axis && akbar_y < y_axis && flag[akbar_x-1][akbar_y] == false)
    {
        destination_no(flag ,input, x_axis, y_axis , akbar_x-1 , akbar_y);
       
    }
    
     if (input[akbar_x+1][akbar_y] != '#' && akbar_x+1 >=0 && akbar_y >=0 && akbar_x+1 < x_axis && akbar_y < y_axis && flag[akbar_x+1][akbar_y] == false)
    {
         destination_no(flag ,input, x_axis, y_axis , akbar_x+1 , akbar_y);
       
    }
    
     if (input[akbar_x][akbar_y-1] != '#' && akbar_x >=0 && akbar_y-1 >=0 && akbar_x < x_axis && akbar_y - 1 < y_axis && flag[akbar_x][akbar_y - 1] == false)
    {
         destination_no(flag ,input, x_axis, y_axis , akbar_x , akbar_y-1);
    }
    
     if (input[akbar_x][akbar_y+1] != '#' && akbar_x >=0 && akbar_y+1 >=0 && akbar_x < x_axis && akbar_y + 1 < y_axis && flag[akbar_x][akbar_y+1] == false)
    {
         destination_no(flag ,input, x_axis, y_axis , akbar_x , akbar_y + 1);
      
    }
    
    return 0;
}











