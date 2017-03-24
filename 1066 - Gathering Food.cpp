#include <bits/stdc++.h>

using namespace std;



string graph[11];
int N ;

struct english_letter
{
    int row ;
    int column ;
}letters[26];

int bfs(int start_row , int start_column , int end_row , int end_column)
{
    //cout << "Start row = " << start_row << " Start column = " << start_column << " End Row = " << end_row << "End col = " << end_column << endl;
    int ans = -1;

    bool visited[11][11] ;

    for(int i = 0 ; i < 11 ; i++)
    {
        for(int j = 0 ; j < 11 ; j++)
        {
            visited[i][j] = false;
        }
    }

    queue <int> row_line;
    queue <int> column_line;
    queue <int> step_count;

    row_line.push(start_row);
    column_line.push(start_column);
    step_count.push(0);

    visited[start_row][start_column] = true;


    while(row_line.empty() != true)
    {
        int current_row = row_line.front();
        row_line.pop();

        int current_column = column_line.front();
        column_line.pop();

        int current_step = step_count.front();
        step_count.pop();

        //cout << "Current Row = " << current_row << " Current col = " << current_column << " Step Count = " << current_step << endl;

        if(current_row == end_row && current_column == end_column)
        {
            ans = current_step;
            //cout << "ANS = " << ans << endl;
            return ans;
        }
        if(graph[current_row][current_column] > graph[end_row][end_column] && graph[current_row][current_column] <= 'Z' && (current_row != start_row || current_column != start_column))
        {
           // cout << "Activated" << endl ;
            continue;
        }

        if(current_row+1 < N )
        {
            if(graph[current_row+1][current_column] != '#' && visited[current_row+1][current_column] == false)
            {
                row_line.push(current_row+1);
                column_line.push(current_column);
                step_count.push(current_step+1);
                visited[current_row+1][current_column] = true;
            }

        }
        if(current_row-1 >= 0 )
        {
            if(graph[current_row-1][current_column] != '#' && visited[current_row-1][current_column] == false)
            {
                row_line.push(current_row-1);
                column_line.push(current_column);
                step_count.push(current_step+1);
                visited[current_row-1][current_column] = true;
            }

        }
        if(current_column+1 < N )
        {
            if(graph[current_row][current_column+1] != '#' && visited[current_row][current_column+1] == false)
            {
                row_line.push(current_row);
                column_line.push(current_column+1);
                step_count.push(current_step+1);
                visited[current_row][current_column+1] = true;
            }

        }
        if(current_column-1 >= 0)
        {
            if(graph[current_row][current_column-1] != '#' && visited[current_row][current_column-1] == false)
            {
                row_line.push(current_row);
                column_line.push(current_column-1);
                step_count.push(current_step+1);
                visited[current_row][current_column-1] = true;
            }

        }
    }
    return ans ;

}

int main()
{
    int test_case , no_of_letters , ans , total_step ;
    bool isPossible;

    scanf("%d", &test_case);

    for(int k = 0 ; k < test_case ; k++)
    {

        scanf("%d", &N);

        for(int i = 0 ; i < N ; i++)
        {
            graph[i].clear();

            cin >> graph[i];
        }

        no_of_letters = 0;

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(graph[i][j] >= 'A' && graph[i][j] <= 'Z')
                {
                    letters[graph[i][j] - 'A'].row = i;
                    letters[graph[i][j] - 'A'].column = j;
                    no_of_letters++;
                }
            }
        }

        ans = 0;
        isPossible = true;

        for(int i = 0 ; i < no_of_letters -1 ; i++ )
        {
            total_step = bfs(letters[i].row , letters[i].column , letters[i+1].row , letters[i+1].column);
            if(total_step == -1)
            {
                isPossible = false;
                break;
            }
            else ans+= total_step;
        }

        if(isPossible)
        {
            printf("Case %d: %d\n", k+1 , ans);
        }
        else
        {
            printf("Case %d: Impossible\n", k+1);
        }

    }


    return 0;
}
