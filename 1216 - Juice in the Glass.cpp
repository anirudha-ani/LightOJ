#include <bits/stdc++.h>

using namespace std;
//http://light-online-judge.blogspot.com/2012/05/1216-juice-in-glass.html
//V = 1/3 * H * ( R1*R1 + R2*R1 + R2*R2 )
//R1 =  r1 .
//R2 = r2 + (r1-r2)*p/h
//H=p

#define PI acos(-1.0)

int main()
{
    int i,test;
    double r1,r2,h,p,R,V;
    cin>>test;
    for(i=1;i<=test;i++)
    {
        cin>>r1>>r2>>h>>p;
        R= r2 + (r1-r2)*(double(p)/h);

        V = 1/3.0 * PI * p *( R*R + R*r2 + r2*r2 );
        printf("Case %d: %f\n",i,V);
    }
    return 0;
}
