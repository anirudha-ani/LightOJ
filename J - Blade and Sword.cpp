#include <bits/stdc++.h>

using namespace std;
string graph[205];
bool visited[205][205];
struct portal
{
    int row;
    int column;
    bool portaled_from ;
}portals[40005];

int T ,row , column , p_row , p_column , number_of_portals;

int bfs()
{
    int ans = -1;


    queue <int> row_line;
    queue <int> column_line;
    queue <int> step_counter;
    queue <bool> portal_status;

    row_line.push(p_row);
    column_line.push(p_column);
    step_counter.push(0);
    portal_status.push(false);

    visited[p_row][p_column] = true;

    while(row_line.empty() != true)
    {
        int current_portal = -1;
        int current_row = row_line.front();
        row_line.pop();

        int current_column = column_line.front();
        column_line.pop();

        int current_step = step_counter.front();
        step_counter.pop();

        bool isPortalled = portal_status.front();
        portal_status.pop();
        //cout << "Row = " << current_row+1 << " Column = " << current_column+1 << " Current step = " << current_step << endl;

        if(graph[current_row][current_column] == 'D')
        {
            ans = current_step;
            return ans;
        }
        else if(graph[current_row][current_column] == '*')
        {
            for(int i = 0 ; i < number_of_portals ;i++)
            {
                if(portals[i].row == current_row && portals[i].column == current_column)
                {
                    current_portal = i;
                    continue;
                }
                if(portals[i].portaled_from == false)
                {
                    row_line.push(portals[i].row);
                    column_line.push(portals[i].column);
                    step_counter.push(current_step+1);
                    portals[i].portaled_from = true;
                    visited[portals[i].row][portals[i].column] = true;
                    portal_status.push(true);

                }
            }
        }
        if((graph[current_row][current_column] == '*') && isPortalled == false) continue ;

            if(graph[current_row + 1][current_column] != '#' && visited[current_row +1][current_column] == false)
            {
                row_line.push(current_row+1);
                column_line.push(current_column);
                step_counter.push(current_step+1);
                visited[current_row+1][current_column] = true;
                portal_status.push(false);
            }
            if(graph[current_row - 1][current_column] != '#' && visited[current_row -1][current_column] == false)
            {
                row_line.push(current_row-1);
                column_line.push(current_column);
                step_counter.push(current_step+1);
                visited[current_row-1][current_column] = true;
                portal_status.push(false);
            }
            if(graph[current_row][current_column+1] != '#' && visited[current_row][current_column+1] == false)
            {
                row_line.push(current_row);
                column_line.push(current_column+1);
                step_counter.push(current_step+1);
                visited[current_row][current_column+1] = true;
                portal_status.push(false);
            }
            if(graph[current_row ][current_column-1] != '#' && visited[current_row][current_column-1] == false)
            {
                row_line.push(current_row);
                column_line.push(current_column-1);
                step_counter.push(current_step+1);
                visited[current_row][current_column-1] = true;
                portal_status.push(false);
            }



    }



    return ans ;
}

int main()
{
    int T ;

    scanf("%d", &T);

    for(int k = 0 ; k < T ; k++)
    {
        scanf("%d %d",&row , &column);
         for(int i = 0 ; i < row ; i++)
        {
            graph[i].clear();
            cin >> graph[i];
        }
        number_of_portals = 0;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < column ; j++)
            {
                visited[i][j] = false;

                if(graph[i][j] == 'P')
                {
                    p_row = i ;
                    p_column = j;
                }
                else if(graph[i][j] == '*')
                {
                    portals[number_of_portals].row = i;
                    portals[number_of_portals].column = j;
                    portals[number_of_portals].portaled_from = false;
                    number_of_portals++;
                }
            }
        }
        int ans = bfs();

        if(ans == -1)
            printf("Case %d: impossible\n",k+1);
        else
            printf("Case %d: %d\n",k+1 , ans);

    }



    return 0;
}
