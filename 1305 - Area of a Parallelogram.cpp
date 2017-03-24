#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int Ax , Ay , Bx, By ,Cx ,Cy , test_case ;
    int Dx , Dy , midX , midY , area;

    scanf("%d" ,  &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d %d %d %d %d %d", &Ax , &Ay , &Bx, &By ,&Cx ,&Cy);

       // midX = ()/2.0;
        //midY = ()/2.0;

        Dx = (Ax + Cx) - Bx;
        Dy = (Ay + Cy) - By;

        area = ((Bx - Ax) * (Dy - Ay)) - ((Dx - Ax)*(By - Ay));

        area = abs(area);

        printf("Case %d: %d %d %d\n", i+1 , Dx , Dy ,area);
    }
    return 0;
}
