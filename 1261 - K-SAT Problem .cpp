#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T , n , m , K;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        bool marker[35] ;
        bool found[35] ;

        for(int j = 0 ; j < 35 ; j++)
        {
            marker[j] = false;
            found[j] = false;
        }

        vector <int > query[35];

        scanf("%d %d %d", &n , &m , &K);

        for(int j = 0 ; j < n ; j++)
        {
            int input;

            for(int k = 0 ; k < K ; k++)
            {
                scanf("%d", &input);
                query[j].push_back(input);
            }
        }
        int set_size;
        scanf("%d", &set_size);

        int set_input;

        for(int k = 0 ; k < set_size ; k++)
        {
            scanf("%d", &set_input);
            marker[set_input] = true;
        }



        for(int k = 0 ; k < n ; k++)
        {
            int length = query[k].size();

            for(int l = 0 ; l < length ; l++)
            {
                if(query[k][l]<0 && marker[query[k][l]*-1] == false)
                {
                    found[k] = true;
                    break;
                }
                else if(query[k][l] > 0 && marker[query[k][l]] == true)
                {
                    found[k] = true;
                    break;
                }
            }
        }
        bool yes = true;
        for(int l = 0 ; l < n ;l++)
        {
            if(found[l] == false)
            {
                yes = false;
            }
        }
        if(!yes)
        {
            printf("Case %d: No\n",i+1);
        }
        else
        {
             printf("Case %d: Yes\n",i+1);
        }
    }
    return 0;
}
