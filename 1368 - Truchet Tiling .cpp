#include <bits/stdc++.h>

using namespace std;

string graph[105];
double PI = acos(-1.0);
double area[6];
int test_case , R , C , query_no , row , column;
double BFS(int row , int column)
{
    double answer = 0.0;

    queue<int> row_line;
    queue<int> column_line;
    queue<int> type_line;
    bool visited[105][105][6];
    int pushing;
    for(int i = 0 ; i < 105 ; i++)
    {
        for(int j = 0 ; j < 105 ; j++)
        {
            for(int k = 0 ; k < 6 ; k++)
            {
                visited[i][j][k] = false;
            }

        }
    }
    if(row%2 != 0)
    {
        int ROW = row/2;
        int COL = column/2;

        if(graph[ROW][COL] == '0')
        {
            pushing = 1;
            type_line.push(1);
        }
        else
        {
            pushing = 4;
            type_line.push(4);
        }
        row_line.push(ROW);
        column_line.push(COL);
        visited[ROW][COL][pushing] = true;
    }
    else if(row == 0 || column == 0)
    {
        if(row == 0 && column == 0)
        {
            if(graph[0][0] == '0')
            {
                pushing = 0;
                type_line.push(0);
            }
            else
            {
                pushing = 4;
                type_line.push(4);
            }
            row_line.push(0);
            column_line.push(0);
            visited[0][0][pushing] = true;
        }
        else if(row == 0)
        {
            int COL = (column/2) - 1;

                if(graph[0][COL] == '0')
                {
                    pushing = 1;
                    type_line.push(1);
                }
                else
                {
                    pushing = 5;
                    type_line.push(5);
                }
            row_line.push(0);
            column_line.push(COL);
            visited[0][COL][pushing] = true;

        }
        else if(column == 0)
        {
            int ROW = (row/2) - 1;
            if(graph[ROW][0] == '0')
            {
                pushing = 1;
                type_line.push(1);
            }
            else
            {
                pushing = 3;
                type_line.push(3);
            }
            row_line.push(ROW);
            column_line.push(0);
            visited[ROW][0][pushing] = true;
        }
    }
    else
    {
        int ROW = (row/2)-1;
        int COL = (column/2) - 1;
        if(graph[ROW][COL] == '0')
        {
            pushing = 2;
            type_line.push(2);
        }
        else
        {
            pushing = 4;
            type_line.push(4);
        }
        row_line.push(ROW);
        column_line.push(COL);
        visited[ROW][COL][pushing] = true;
    }

    while(row_line.empty() != true)
    {

        int current_row = row_line.front();
        int current_column = column_line.front();
        int current_type = type_line.front();

//        cout << "Current Row = " << current_row << endl;
//        cout << "Current Column = " << current_column << endl;
//        cout << "Current Type = " << current_type << endl;
//        cout << "Area = " << area[current_type]<< endl;
        answer += area[current_type];
       // cout << "Answer = " << answer << endl;

        row_line.pop();
        column_line.pop();
        type_line.pop();

        if(current_type == 0)
        {
            if(current_column - 1 >=0 )
            {

                if(graph[current_row][current_column - 1] == '0' &&  visited[current_row][current_column - 1][1] != true)
                {
                    visited[current_row][current_column - 1][1] = true;
                    type_line.push(1);
                    row_line.push(current_row);
                    column_line.push(current_column - 1);
                }
                else if (graph[current_row][current_column - 1] == '1' &&  visited[current_row][current_column - 1][5] != true)
                {
                    visited[current_row][current_column - 1][5] = true;
                    type_line.push(5);
                    row_line.push(current_row);
                    column_line.push(current_column - 1);
                }

            }
            if(current_row - 1 >= 0 )
            {
                if(graph[current_row - 1][current_column] == '0' && visited[current_row - 1][current_column][1] == false)
                {
                    visited[current_row - 1][current_column][1] = true;
                    type_line.push(1);
                    row_line.push(current_row - 1);
                    column_line.push(current_column );
                }
                else  if(graph[current_row - 1][current_column] == '1' && visited[current_row - 1][current_column][3] == false)
                {
                    visited[current_row - 1][current_column][3] = true;
                    type_line.push(3);
                    row_line.push(current_row - 1);
                    column_line.push(current_column );
                }

            }
        }

        else if(current_type == 1)
        {
            if(current_column - 1 >=0 )
            {
                if(graph[current_row][current_column - 1] == '0'&& visited[current_row][current_column - 1][2] == false)
                {
                    visited[current_row][current_column - 1][2] = true;
                    type_line.push(2);
                    row_line.push(current_row);
                    column_line.push(current_column - 1);
                }
                else if(graph[current_row][current_column - 1] == '1'&& visited[current_row][current_column - 1][4] == false)
                {
                    visited[current_row][current_column - 1][4] = true;
                    type_line.push(4);
                    row_line.push(current_row);
                    column_line.push(current_column - 1);
                }

            }
            if(current_row - 1 >= 0 )
            {
                if(graph[current_row - 1][current_column] == '0'&& visited[current_row - 1][current_column][2] == false)
                {
                    visited[current_row - 1][current_column][2] = true;
                    type_line.push(2);
                    row_line.push(current_row - 1);
                    column_line.push(current_column);
                }
                else if(graph[current_row - 1][current_column] == '1'&& visited[current_row - 1][current_column][4] == false)
                {
                    visited[current_row - 1][current_column][4] = true;
                    type_line.push(4);
                    row_line.push(current_row - 1);
                    column_line.push(current_column);
                }

            }
            if(current_row + 1 < R)
            {
                if(graph[current_row + 1][current_column] == '0'  && visited[current_row + 1][current_column][0] == false)
                {
                    visited[current_row + 1][current_column][0] = true;
                    type_line.push(0);
                    row_line.push(current_row + 1);
                    column_line.push(current_column);
                }
                else if(graph[current_row + 1][current_column] == '1'  && visited[current_row + 1][current_column][4] == false)
                {
                    visited[current_row + 1][current_column][4] = true;
                    type_line.push(4);
                    row_line.push(current_row + 1);
                    column_line.push(current_column);
                }

            }
            if(current_column + 1 < C)
            {
                if(graph[current_row][current_column+1] == '0'  && visited[current_row][current_column+1][0] == false)
                {
                    visited[current_row][current_column+1][0] = true;
                    type_line.push(0);
                    row_line.push(current_row);
                    column_line.push(current_column + 1);
                }
                else if(graph[current_row][current_column+1] == '1'  && visited[current_row][current_column+1][4] == false)
                {
                    visited[current_row][current_column+1][4] = true;
                    type_line.push(4);
                    row_line.push(current_row);
                    column_line.push(current_column + 1);
                }

            }
        }

        // I finished here

        else if(current_type == 2)
        {
            if(current_row + 1 < R )
            {

                if(graph[current_row + 1][current_column] == '0' && visited[current_row + 1][current_column][1] == false)
                {
                    visited[current_row + 1][current_column][1] = true;
                    type_line.push(1);
                    row_line.push(current_row + 1);
                    column_line.push(current_column);
                }
                else  if(graph[current_row + 1][current_column] == '1' && visited[current_row + 1][current_column][5] == false)
                {
                    visited[current_row + 1][current_column][5] = true;
                    type_line.push(5);
                    row_line.push(current_row + 1);
                    column_line.push(current_column);
                }

            }
            if(current_column + 1 < C )
            {

                if(graph[current_row][current_column+1] == '0'&& visited[current_row][current_column+1][1] == false)
                {
                    visited[current_row][current_column+1][1] = true;
                    type_line.push(1);
                    row_line.push(current_row);
                    column_line.push(current_column + 1);
                }
                else if(graph[current_row][current_column+1] == '1'&& visited[current_row][current_column+1][3] == false)
                {
                    visited[current_row][current_column+1][3] = true;
                    type_line.push(3);
                    row_line.push(current_row);
                    column_line.push(current_column + 1);
                }

            }
        }
        else if(current_type == 3)
        {
            if(current_column - 1 >=0 )
            {
                if(graph[current_row][current_column - 1] == '0' && visited[current_row][current_column - 1][2] == false)
                {
                    visited[current_row][current_column - 1][2] = true;
                    type_line.push(2);
                    row_line.push(current_row);
                    column_line.push(current_column - 1);
                }
                else if(graph[current_row][current_column - 1] == '1' && visited[current_row][current_column - 1][4] == false)
                {
                    visited[current_row][current_column - 1][4] = true;
                    type_line.push(4);
                    row_line.push(current_row);
                    column_line.push(current_column - 1);
                }

            }
            if(current_row + 1 < R )
            {

                if(graph[current_row + 1][current_column] == '0' && visited[current_row + 1][current_column][0] == false)
                {
                    visited[current_row + 1][current_column][0] = true;
                    type_line.push(0);
                    row_line.push(current_row + 1);
                    column_line.push(current_column);
                }
                else  if(graph[current_row + 1][current_column] == '1' && visited[current_row + 1][current_column][4] == false)
                {
                    visited[current_row + 1][current_column][4] = true;
                    type_line.push(4);
                    row_line.push(current_row + 1);
                    column_line.push(current_column);
                }

            }
        }
        else if(current_type == 4)
        {
            if(current_column - 1 >=0)
            {
                if(graph[current_row][current_column - 1] == '0'  && visited[current_row][current_column - 1][1] == false)
                {
                    visited[current_row][current_column - 1][1] = true;
                    type_line.push(1);
                    row_line.push(current_row);
                    column_line.push(current_column - 1);
                }
                else if(graph[current_row][current_column - 1] == '1'  && visited[current_row][current_column - 1][5]== false)
                {
                    visited[current_row][current_column - 1][5] = true;
                    type_line.push(5);
                    row_line.push(current_row);
                    column_line.push(current_column - 1);
                }

            }
            if(current_row - 1 >= 0)
            {
                if(graph[current_row - 1][current_column] == '0'  && visited[current_row - 1][current_column][1] == false)
                {
                    visited[current_row - 1][current_column][1] = true;
                    type_line.push(1);
                    row_line.push(current_row - 1);
                    column_line.push(current_column);
                }
                else if(graph[current_row - 1][current_column] == '1'  && visited[current_row - 1][current_column][3] == false)
                {
                    visited[current_row - 1][current_column][3] = true;
                    type_line.push(3);
                    row_line.push(current_row - 1);
                    column_line.push(current_column);
                }

            }
            if(current_row + 1 < R )
            {
                if(graph[current_row + 1][current_column] == '0' && visited[current_row + 1][current_column][1] == false)
                {
                    visited[current_row + 1][current_column][1] = true;
                    type_line.push(1);
                    row_line.push(current_row + 1);
                    column_line.push(current_column);
                }
                else if(graph[current_row + 1][current_column] == '1' && visited[current_row + 1][current_column][5] == false)
                {
                    visited[current_row + 1][current_column][5] = true;
                    type_line.push(5);
                    row_line.push(current_row + 1);
                    column_line.push(current_column);
                }

            }
            if(current_column + 1 < C )
            {
                if(graph[current_row][current_column+1] == '0' && visited[current_row][current_column+1][1] == false)
                {
                    visited[current_row][current_column+1][1] = true;
                    type_line.push(1);
                    row_line.push(current_row);
                    column_line.push(current_column + 1);
                }
                else if(graph[current_row][current_column+1] == '1' && visited[current_row][current_column+1][3] == false)
                {
                    visited[current_row][current_column+1][3] = true;
                    type_line.push(3);
                    row_line.push(current_row);
                    column_line.push(current_column + 1);
                }

            }
        }
        else if(current_type == 5)
        {
            if(current_row - 1 >= 0 )
            {

                if(graph[current_row - 1][current_column] == '0' && visited[current_row - 1][current_column][2] == false)
                {
                    visited[current_row - 1][current_column][2] = true;
                    type_line.push(2);
                    row_line.push(current_row - 1);
                    column_line.push(current_column);
                }
                else if(graph[current_row - 1][current_column] == '1' && visited[current_row - 1][current_column][4] == false)
                {
                    visited[current_row - 1][current_column][4] = true;
                    type_line.push(4);
                    row_line.push(current_row - 1);
                    column_line.push(current_column);
                }

            }

            if(current_column + 1 < C)
            {

                if(graph[current_row][current_column+1] == '0'  && visited[current_row][current_column+1][0] == false)
                {
                    visited[current_row][current_column+1][0] = true;
                    type_line.push(0);
                    row_line.push(current_row);
                    column_line.push(current_column + 1);
                }
                else if(graph[current_row][current_column+1] == '1'  && visited[current_row][current_column+1][4] == false)
                {
                    visited[current_row][current_column+1][4] = true;
                    type_line.push(4);
                    row_line.push(current_row);
                    column_line.push(current_column + 1);
                }

            }
        }
    }
    return answer;

}

int main()
{

//    freopen("input.txt" , "r", stdin);
//    freopen("output.txt" , "w" , stdout);
    area[0] = PI / 4.0;
    area[1] = 4.0 - (2.0 *area[0]);
    area[2] = area[0];
    area[3] = area[0];
    area[4] = area[1];
    area[5] = area[0];


//    cout << area[0] << endl;
//    cout << area[1] << endl;
    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d %d", &R , &C);

        for(int j = 0 ; j < R ; j++)
        {
            cin >> graph[j];
        }

        scanf("%d", &query_no);

        printf("Case %d:\n",i+1);
        for(int j = 0 ; j < query_no ; j++)
        {
            scanf("%d %d", &row , &column);

            if((row%2 == 0 && column % 2 == 0) || (row%2 != 0 && column%2 != 0))
            {
                printf("%.10lf\n",BFS(row , column));
            }
            else
            {
                printf("0\n", row ,column);
            }

        }
    }
    return 0 ;
}
