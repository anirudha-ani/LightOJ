#include <bits/stdc++.h>

using namespace std;

string graph[25];
bool visited[25][25] ;

int bfs(int m , int  n)
{

    int ans = 0;
    queue <int> queue_for_m;
    queue <int> queue_for_n;
    queue <int> queue_for_steps;

    queue_for_m.push(m);
    queue_for_n.push(n);
    queue_for_steps.push(0);

    while(queue_for_m.empty() != true)
    {
        int current_m = queue_for_m.front();
        int current_n = queue_for_n.front();
        int current_steps = queue_for_steps.front();


        queue_for_m.pop();
        queue_for_n.pop();
        queue_for_steps.pop();

        if(graph[current_m][current_n] == 'h' )
        {
            ans = current_steps;
            break;
        }
        if(graph[current_m+1][current_n] != '#' && graph[current_m+1][current_n] != 'm'  && visited[current_m+1][current_n] != true)
        {
            queue_for_m.push(current_m+1);
            queue_for_n.push(current_n);
            queue_for_steps.push(current_steps+1);
            visited[current_m+1][current_n] = true;
        }
        if(graph[current_m-1][current_n] != '#' && graph[current_m-1][current_n] != 'm'&& visited[current_m-1][current_n] != true)
        {
            queue_for_m.push(current_m-1);
            queue_for_n.push(current_n);
            queue_for_steps.push(current_steps+1);
            visited[current_m-1][current_n] = true;
        }
        if(graph[current_m][current_n+1] != '#' && graph[current_m][current_n+1] != 'm'  && visited[current_m][current_n+1] != true)
        {
            queue_for_m.push(current_m);
            queue_for_n.push(current_n+1);
            queue_for_steps.push(current_steps+1);
            visited[current_m][current_n+1] = true;
        }
        if(graph[current_m][current_n-1] != '#' && graph[current_m][current_n-1] != 'm' && visited[current_m][current_n-1] != true)
        {
            queue_for_m.push(current_m);
            queue_for_n.push(current_n-1);
            queue_for_steps.push(current_steps+1);
            visited[current_m][current_n-1] = true;
        }
    }
    return ans;
}

int main()
{
    int T , m , n , answer;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        answer = 0;
        scanf("%d %d", &m , &n);
        for(int k = 0 ; k < 25 ; k++)
        {
            graph[k].clear();
        }
        for(int j = 0 ; j < m  ; j++)
        {
            cin >> graph[j];
        }

        for(int k = 0 ; k < m ; k++)
        {
            for(int l = 0 ; l < n ;l++)
            {
                if(graph[k][l] == 'a' || graph[k][l] == 'b' || graph[k][l] == 'c')
                {
                    for(int q = 0 ; q < 25 ; q++)
                    {
                        for(int w = 0 ; w < 25 ; w++)
                        {
                            visited[q][w] = false;
                        }
                    }
                    answer = max(answer , bfs(k , l));
                }
            }
        }



        printf("Case %d: %d\n", i+1 , answer);
    }
    return 0;
}
