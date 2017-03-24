#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int x , y ;
    int test_case,ans,ceil_x , floor_x , ceil_y , floor_y;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d %d", &x , &y);
        if(x == 1 || y == 1)
        {
            int ans = x>y? x:y;
            printf("Case %d: %d\n",i+1, ans);
            continue;
        }
        else if(x == 2 || y == 2)
        {
            ans = 0;
            int counter = 0;
            if(x == 2)
            {
                swap(x,y);
            }
            for(int i = 1 ; i <= x ;i++)
            {
                counter++;
                if(counter < 3)
                {
                    ans+=2;
                }
                if(counter == 4)
                {
                    counter = 0;
                }
            }
            printf("Case %d: %d\n",i+1 , ans);
            continue;

        }


        ans = ((x*y)+1)/2;
        printf("Case %d: %d\n",i+1, ans);

    }
    return 0;
}
