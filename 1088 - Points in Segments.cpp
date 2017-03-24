//Given n points (1 dimensional) and q segments, you have to find the number of points that lie in each of the segments. A point pi will lie in a segment A B if A ≤ pi ≤ B.
//
//For example if the points are 1, 4, 6, 8, 10. And the segment is 0 to 5. Then there are 2 points that lie in the segment.
//
//Input
//Input starts with an integer T (≤ 5), denoting the number of test cases.
//
//Each case starts with a line containing two integers n (1 ≤ n ≤ 105) and q (1 ≤ q ≤ 50000). The next line contains n space separated integers denoting the points in ascending order. All the integers are distinct and each of them range in [0, 108].
//
//Each of the next q lines contains two integers Ak Bk (0 ≤ Ak ≤ Bk ≤ 108) denoting a segment.
//
//Output
//For each case, print the case number in a single line. Then for each segment, print the number of points that lie in that segment.


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, n , q ;
    int x[100000] ;

    scanf("%d" , &T);

    for(int w = 0 ; w< T ; w++)
    {
        scanf("%d %d", &n , &q);

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &x[i]);
        }

        printf("Case %d:\n", w+1);

        for(int i = 0 ; i < q ; i++)
        {
            int a , b, c ,d;
            scanf("%d%d" , &a , &b);

            d = upper_bound(x , x+n , b)-x;
            c = lower_bound(x , x+n , a) - x;

            cout << d-c << endl;
        }

    }
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std ;
//int main ()
//{
//    int t , it , i ,n ,q ,a[100005] ,x ,y ,low ,up ;
//
//     scanf ("%d",&t) ;
//    for (it=1 ; it<=t ; it++)
//    {
//       scanf ("%d %d",&n , &q) ;
//        for (i=0 ; i<n ; i++) scanf ("%d",&a[i]) ;
//
//       printf ("Case %d:\n",it) ;
//        for (i=1 ; i<=q ; i++)
//        {
//            scanf ("%d %d",&x,&y) ;
//            low=lower_bound(a, a+n ,x)-a ;
//            up=upper_bound(a, a+n ,y)-a ;
//            int ans=up-low ;
//
//           printf ("%d\n",ans) ;
//
//        }
//
//    }
//
//    return 0 ;
//}
