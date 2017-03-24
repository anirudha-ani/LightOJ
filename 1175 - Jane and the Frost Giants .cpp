#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
bool map [205][205];
int main()
{
    int case_no;

    cin >> case_no;

    for(int i = 0 ; i < case_no ; i++)
    {
        int R , C ;
        cin >> R >> C ;

        for(int i = 0 ; i < R ; i++)
        {
            for(int j = 0 ; j < C ; j++)
                map[i][j] = false ;
        }
       int Jx , Jy , Fx , Fy;

       queue <int> FXX;
       queue <int> FYY;

       int fire_no  = 0;

       for(int i = 0 ; i <  R ; i++)
       {
           string input ;

           cin >> input;

           for(int j = 0 ; j < C ; j++)
           {
               if(input[j] == '.')
               {
                   map[i][j] = true;
               }
               else if(input[j] == 'J')
               {
                   map[i][j] = true;
                   Jx = i ;
                   Jy = j ;
               }
               else if(input[j] == 'F')
               {
                   FXX.push(i);
                   FYY.push(j);
                   fire_no++;
               }
           }

       }

       queue <int> JXX;
       queue <int> JYY;

       queue <int> fire_step;

       JXX.push(Jx);
       JYY.push(Jy);

       while(fire_no > 0)
       {
           fire_step.push(0);
           fire_no--;
       }

       queue <int> moves;

       moves.push(0);

       while (!JXX.empty() && JXX.front() != 0 && JYY.front() !=0 &&  JXX.front() != R - 1 && JYY.front() != C - 1)
       {
           while(fire_step.front() == moves.front())
           {
               int fire_x = FXX.front();
               int fire_y = FYY.front();

               if(fire_x + 1 < R && map[fire_x + 1][fire_y] != false)
               {
                    map[fire_x + 1][fire_y] = false;
                    FXX.push(fire_x + 1);
                    FYY.push(fire_y);
                    fire_step.push(fire_step.front() + 1);
               }
               if(fire_x - 1 >= 0 && map[fire_x - 1][fire_y] != false)
               {
                    map[fire_x - 1][fire_y] = false;
                    FXX.push(fire_x - 1);
                    FYY.push(fire_y);
                    fire_step.push(fire_step.front() + 1);
               }
               if(fire_y - 1 >= 0 && map[fire_x][fire_y - 1] != false)
               {
                    map[fire_x][fire_y - 1] = false;
                    FXX.push(fire_x);
                    FYY.push(fire_y - 1);
                    fire_step.push(fire_step.front() + 1);
               }
               if(fire_y + 1 < C && map[fire_x][fire_y + 1] != false)
               {
                    map[fire_x][fire_y + 1] = false;
                    FXX.push(fire_x);
                    FYY.push(fire_y + 1);
                    fire_step.push(fire_step.front() + 1);
               }

               FXX.pop();
               FYY.pop();
               fire_step.pop();

           }


           int j_x = JXX.front();
           int j_y = JYY.front();
           int m = moves.front();
           if(j_x + 1 < R && map[j_x + 1][j_y] == true)
           {
                map[j_x + 1][j_y] = false;
                JXX.push(j_x + 1);
                JYY.push(j_y);
                moves.push(m + 1);
           }
           if(j_x - 1 >= 0 && map[j_x - 1][j_y] != false)
           {
                map[j_x - 1][j_y] = false;
                JXX.push(j_x - 1);
                JYY.push(j_y);
                moves.push(m + 1);
           }
           if(j_y - 1 >= 0 && map[j_x][j_y - 1] != false)
           {
                map[j_x][j_y - 1] = false;
                JXX.push(j_x);
                JYY.push(j_y - 1);
                moves.push(m + 1);
           }
           if(j_y + 1 < C && map[j_x][j_y + 1] != false)
           {
               map[j_x][j_y + 1] = false;
                JXX.push(j_x);
                JYY.push(j_y + 1);
                moves.push(m + 1);
           }

           JYY.pop();
           JXX.pop();
           moves.pop();
       }
       if(JXX.empty())
       {
           cout << "Case "<< i + 1<<": IMPOSSIBLE"<<endl;
       }
       else
       {
           cout << "Case "<<i+1<<": "<< moves.front()+1 << endl;
       }

    }
    return 0;
}
