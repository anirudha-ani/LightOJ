#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
vector <int> graph[20005];
int mark[20005];
bool visited[20005];
int one_count ;
int zero_count ;
bool exist[20005];
void bfs(int node)
{
    mark[node] = 1;
    visited[node] = true;
    queue <int> q;
    one_count++;

    //for(int )
    q.push(node);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int length = graph[u].size();

        for(int v = 0 ; v < length ; v++)
        {
            if(( mark[graph[u][v]] == -1) && visited[graph[u][v]] !=true)
            {
                visited[graph[u][v]] = true;
                mark[graph[u][v]] = 1 - mark[u];
                if(1 - mark[u] == 0)
                {
                    zero_count++;
                }
                else
                {
                    one_count++;
                }
                q.push(graph[u][v]);
            }
        }
    }
}

int main()
{
    int test_case , n , x , y;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {


        scanf("%d", &n);

        for(int j = 0 ; j < 20000 ; j++)
        {
            graph[j].clear();
            mark[j] = -1;
            visited[j] = false;
            exist[j] = false;
        }
        one_count = 0;
        zero_count = 0;

        for(int  j = 0 ; j < n ; j++)
        {
            scanf("%d %d", &x , &y);
            exist[x-1] = true;
            exist[y-1] = true;
            graph[x-1].push_back(y-1) ;
            graph[y-1].push_back(x-1) ;
        }
        int ans = 0;
        for(int j = 0 ; j < 20000 ; j++)
        {
            if(visited[j] == false&&exist[j] == true)
            {
                one_count = 0 ;
                zero_count = 0;
                bfs(j);
                ans += max(one_count , zero_count);
            }
        }


        printf("Case %d: %d\n", i+1 , ans);
    }
    return 0;
}
