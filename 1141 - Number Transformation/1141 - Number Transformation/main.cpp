//
//  main.cpp
//  1141 - Number Transformation
//
//  Created by Anirudha Paul on 3/30/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

int primeNumber();

bool prime[1005];

int main()
{
    primeNumber();
    int testcase, a , b;
    
    scanf("%d", &testcase);
    
    for (int t = 0 ; t < testcase ; t++)
    {
        scanf("%d %d" , &a , &b);
       
        int factors[32];
        
        
        int number = 0;
        int wrong = -1;
        
        if (prime[b] != true)
        {
            for (int i = 2 ; i < b ; i++)
            {
                if (prime[i] == true)
                {
                    if (b % i == 0)
                    {
                        factors[number] = i;
                        number ++ ;
                    }
                }
            }
            
        }
        else
        {
            printf("Case %d: %d\n",t+1, wrong);
            continue;
        }
      
     
   
        queue<int> queue1;
        
        queue1.push(a);
        
        int number_of_wave=0;
        int number_of_element = 1;
        int number_of_ne = number_of_element;
        number_of_ne = number_of_ne * number;
        

        
        for (int i = 0; i<number ; i++)
        {
            
            printf("Facors : %d\n", factors[i]);
            
        }

        
        while(queue1.front() != b && queue1.empty()!=true )
        {
            int p = queue1.front();
            queue1.pop();
            
            number_of_element--;
            
            if(number_of_element == 0)
            {
                number_of_element = number_of_ne;
                number_of_ne = number_of_ne * number;
                number_of_wave++;
                char k = getchar();
                
            }
            
            for (int i = 0; i<number ; i++)
            {
                
                if( (p + factors[i]) <= b )
                {
                    queue1.push(p+factors[i]);
                    printf("At level %d for p = %d: Pushing : %d\n", number_of_wave ,p, p + factors[i]);
                }
                
            }
            
            
        }
    
        if(queue1.front() == b )
        {
            printf("Case %d: %d\n",t+1, number_of_wave);
        }
        else
        {
            printf("Case %d: %d\n",t+1, wrong);
        }
        
        
    }
    
    
    return 0;
    
    
    
}

int primeNumber ()
{
   
        int limit = 1005;
    
    
        for (int i = 0 ; i < limit ; i++)
        {
            prime[i] = true ;
        }
    
        
        for (int i = 2 ; i < limit; i++)
        {
            if (prime[i] == true)
            {
                for (int j = 2; j*i < limit ; j++)
                {
                    prime[j*i] = false;
                }
            }
        }
    
        
        return 0;
    
}
