//
//  main.cpp
//  1214 - Large Division
//
//  Created by Anirudha Paul on 1/14/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    long long int T;
    string a ;
    long long int b , length ,remainder;
    cin >> T;
    
    for(int i = 0 ; i < T ; i++)
    {
        cin >> a >> b;
        
        if(b<0) b *= -1;
        
        length = a.length();
        remainder = 0;
        for(int j =0 ; j< length ; j++)
        {
            if(a[j] == '-')
                continue;
            
            remainder = remainder + a[j] - '0';
            
            if(remainder >= b)
                remainder =remainder%b;
            
            if(j != length -1 && remainder <b)
                remainder *= 10;
            else if( j == length - 1 && remainder >b)
                remainder =remainder%b;
        }
        if(remainder == 0)
            printf("Case %d: divisible\n",i+1);
        else
            printf("Case %d: not divisible\n" , i+1);
        
    }
    return 0;
}
