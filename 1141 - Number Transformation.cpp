#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

bool prime[1005] ;
bool visited[1005];
int bfs(int s , int t)
{
    int ans = -1;
    queue<int> query;
    queue <int> steps;
    query.push(s);
    steps.push(0);
    while(steps.empty()!= true)
    {
        int current_s = query.front();
        query.pop();
        int currentstep = steps.front();
        steps.pop();
        visited[current_s] = true;
        if(current_s == t)
        {
            ans = currentstep;
            break;
        }
        for(int i = 2 ; i<current_s ;i++)
        {
            if(prime[i] == true && current_s %i == 0)
            {
                if(current_s +i <= t && visited[current_s +i] == false)
                {
                    query.push(current_s +i);
                    steps.push(currentstep+1);
                }
            }
        }
    }
    return ans;

}

int main()
{
    for(int i = 0 ; i < 1005 ; i++)
    {
        prime[i] = true;
        visited[i] = false;
    }
    for(int i = 2 ; i < 1005 ; i++)
    {
        if(prime[i] == true)
        {
            for(int j = 2 ; j*i < 1005 ; j++)
            {
                prime[j*i] = false;
            }
        }
    }


    int T ,s ,t;
    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
         for(int i = 0 ; i < 1005 ; i++)
        {
            visited[i] = false;
        }
        scanf("%d %d",&s , &t);
        printf("Case %d: %d\n",i+1 , bfs(s,t));
    }
    return 0;
}
