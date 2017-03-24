#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int T , a , b , ans;

    scanf("%d", &T);

    for(int i = 0 ; i < T; i++)
    {
        scanf("%d %d", &a , &b);

        ans= (b/3)*2 - ((a-1)/3)*2;
        //cout << ans <<endl;
        if((a-1)%3 == 2) ans--;
        //cout << ans <<endl;
        if(b%3 == 2) ans++;
        //cout << ans <<endl;
        printf("Case %d: %d\n",i+1,ans);
    }
    return 0;
}
