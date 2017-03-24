#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int test_case;
    double v1 , v2 , v3 , a1 , a2 , t1 , t2 ,t, distance , bird_distance , distance1 , distance2;
    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%lf %lf %lf %lf %lf", &v1 , &v2 , &v3 , &a1 , &a2);

        t1 = 1.0 * v1/a1;
        t2 = 1.0 * v2/a2;
        if(t1>t2)
        {
            t = t1;
        }
        else
        {
            t = t2;
        }
        distance1 = 1.0*((1.0*v1 * t1) - (1.0* a1 * t1 *t1) /2.0);
        distance2 = 1.0*((1.0*v2 * t2) - (1.0* a2 * t2 *t2) /2.0);
        distance = (distance1 + distance2);
        bird_distance = 1.0*v3 * t;

        printf("Case %d: %f %f\n", i+1 , distance , bird_distance);
    }
    return 0;
}
