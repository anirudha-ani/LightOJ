#include <cstdio>

using namespace std;

int main()
{
    int test_case ;

    long long int n , m , answer;

    scanf("%d", &test_case);

    for(int i= 0 ; i < test_case ; i++)
    {
        scanf("%lld %lld", &n , &m);

        answer = (n*m)/2;

        printf("Case %d: %lld\n", i+1 , answer);
    }
    return 0;
}
