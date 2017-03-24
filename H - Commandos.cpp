#include <bits/stdc++.h>

using namespace std;

bool graph[105][105];
int max_time1[105];
int max_time2[105];
bool visited[105];

int bfs(int start , int end , int nodes)
{
    for(int i = 0 ; i < nodes ; i++)
    {
        visited[i] = false;
    }

    queue <int> waiting;
    queue <int> stepnumber;

    waiting.push(start);
    stepnumber.push(0);
    visited[start] = true;

    while(waiting.empty() != true)
    {
        int current_node = waiting.front();
        waiting.pop();
        int current_step = stepnumber.front();
        stepnumber.pop();

        if(current_node == end) return current_step;

        for(int j = 0 ; j < nodes ; j++)
        {
            if(graph[current_node][j] == true && visited[j] == false)
            {
                waiting.push(j);
                stepnumber.push(current_step + 1 );
                visited[j] = true;
            }
        }

    }
}
int main()
{
    int test_case , nodes , edges , start_point , end_point , u , v , max_complete , max_return , answer;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d", &nodes);

        scanf("%d", &edges);

        for(int j = 0 ; j < 105 ; j++)
        {
            max_time1[j] = 0;
            max_time2[j] = 0;
            for(int k = 0 ; k < 105 ; k++)
            {
                graph[j][k] = false;
            }
        }

        for(int j = 0 ; j < edges ; j++)
        {
            scanf("%d %d", &u , &v);
            graph[u][v] = true;
            graph[v][u] = true;
        }

        scanf("%d %d", &start_point , &end_point);


        for(int j = 0 ; j < nodes ; j++)
        {
            max_time1[j] += bfs(start_point , j , nodes);
        }

        for(int j = 0 ; j < nodes ; j++)
        {
            max_time2[j] += bfs(j , end_point , nodes);
        }

        answer = 0;
        for(int j = 0 ; j < nodes ; j++)
        {
            answer = max(answer , max_time1[j] + max_time2[j]);
        }

        printf("Case %d: %d\n", i+1 , answer);
    }
    return 0;
}
