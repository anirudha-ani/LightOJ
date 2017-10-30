#include <bits/stdc++.h>

using namespace std ;

const int N = 5000005;
int lowest_prime_factor[N + 1];
//int phi[N + 1];
unsigned long long int cumphi[N+1];

unsigned long long int phix(unsigned long long int i)
{
    return sqrt(cumphi[i] - cumphi[i-1]);
}


vector<int> prime_list;

void calc_sieve()
{
    cumphi[1] = 1;
    unsigned long long int phi ;
    for (int i = 2; i <= N; ++i)
    {
        if (lowest_prime_factor[i] == 0)
        {
            lowest_prime_factor[i] = i;
            phi = i - 1;
            prime_list.push_back(i);
        }
        else
        {

            if (lowest_prime_factor[i] == lowest_prime_factor[i / lowest_prime_factor[i]])
                phi = phix(i / lowest_prime_factor[i]) * lowest_prime_factor[i];
            else
                phi = phix(i / lowest_prime_factor[i]) * (lowest_prime_factor[i] - 1);
        }
        cumphi[i] = cumphi[i-1] + (phi * phi);
        for (int j = 0; j < (int)prime_list.size() && prime_list[j] <= lowest_prime_factor[i] && i * prime_list[j] <= N; ++j)
            lowest_prime_factor[i * prime_list[j]] = prime_list[j];
    }
}

int main()
{
    //freopen("output.txt" , "w" , stdout);
    int T;
    calc_sieve();
    //cout << cumphi[5000000] << endl ;

    scanf("%d", &T);

    unsigned long long int input1 , input2 , phi1 , phi2 , result ;

    for(int i = 0 ; i < T ; i++)
    {
        //cin >> input1 >> input2 ;
        scanf("%llu %llu", &input1 , &input2);
        if(input1 > input2)
        {
            swap(input1 , input2);
        }

        result = cumphi[input2]- cumphi[input1-1]; ;
        //cout << "Case " << i+1 << ": " << result << endl ;
        printf("Case %d: %llu\n", i+1 , result);
    }
    return 0;
}
