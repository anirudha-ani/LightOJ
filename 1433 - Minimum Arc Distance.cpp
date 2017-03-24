#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    long long int Ox , Oy , Ax, Ay , Bx , By;

    int T;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%lld %lld %lld %lld %lld %lld", &Ox , &Oy , &Ax, &Ay , &Bx , &By);

        double OA = sqrt(((Ox-Ax)*(Ox-Ax))+((Oy-Ay)*(Oy-Ay)));
        double OB = sqrt(((Ox-Bx)*(Ox-Bx))+((Oy-By)*(Oy-By)));

        //cout << "OA = " << OA << " OB = " << OB << endl;
        double AB = sqrt(((Bx-Ax)*(Bx-Ax))+((By-Ay)*(By-Ay)));

        double arc_distance = 1.0* OA* acos(1.0*((OA*OA + OB*OB - AB*AB)/(2.0*OA*OB)));

        printf("Case %d: %f\n",i+1 , arc_distance );
    }
    return 0;
}
