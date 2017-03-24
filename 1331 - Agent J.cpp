#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int test_case;

    scanf("%d", &test_case);

    double R1 , R2 , R3;
    double a , b , c , s , area_of_triangle , areaR1 , areaR2 , areaR3 , result;
    double A , B , C;

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%lf %lf %lf" , &R1 , &R2 ,&R3);

        a = R1 + R2;
        b = R2 + R3;
        c = R3 + R1;

        s = (a+b+c)/2 ;

        area_of_triangle = sqrt(s * (s-a) * (s-b) * (s-c));

        A = acos((b*b+c*c-a*a)/(2*b*c));
        B = acos((c*c+a*a-b*b)/(2*a*c));
        C = acos((a*a+b*b-c*c)/(2*a*b));

        areaR1 = R1 * R1 * B ;
        areaR2 = R2 * R2 * C ;
        areaR3 = R3 * R3 * A ;

        result = area_of_triangle - 0.5 * (areaR1 + areaR2 + areaR3)  ;

        printf("Case %d: %.10lf\n", i+1 , result);

    }
    return 0;
}
