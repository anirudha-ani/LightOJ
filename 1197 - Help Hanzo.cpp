#include <iostream>
#include <cstdio>
#include <new>
#include <math.h>

using namespace std;

//এইটাতে double সিভ use করতে হয় । কারণ 1000000000 পর্যন্ত সিভ দিয়ে প্রাইম বের করলে TLE খাবে memory ৯৬০ MB র মত লাগে
//তাই কম টাইমের এবং মেমোরিতে করার জন্য root পর্যন্ত সিভ করে তারপর সেই টা দিয়ে given range এ আবার সিভ মেথড apply করলেই
//voila !!! :-D

int main(int argc, const char * argv[])
{

    int cases;

    scanf("%d", &cases);

    for ( int i = 0 ; i < cases ; i++)
    {
        int count = 0;
        int lowerLimit , limit ;
        scanf ( "%d %d" , &lowerLimit , &limit);

        int range = sqrt(limit);

        bool *prime;

        prime =  new bool[range+1];

        for (int i = 0 ; i <=range ; i++)
        {
            prime[i] = true ;
        }


        for (int i = 2 ; i <= range; i++)
        {
            if (prime[i] == true)
            {
                for (int j = 2; j*i <=range ; j++)
                {
                    prime[j*i] = false;
                }
            }
        }



        for (int i = lowerLimit ; i <= limit ; i++)
        {
           if (i <= range && i != 1 && prime [i] == true)
               {
                  count++;
               }
           else if (i > range)
               {
                   int flag = 1;
                   for (int x = 2 ; x <=range ; x++)
                   {
                       if (prime [x] == true && i%x == 0)
                       {
                           flag = 0;
                           break;
                       }
                   }
                   if (flag == 1)
                   {
                       count ++;
                   }
               }

        }
        cout << "Case " <<i+1 << ": " << count <<endl ;
        delete [] prime;

    }

    return 0;
}
