#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int test_case , end_index , current_index;
    string pages[100000];
    string command , go_page;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        cout <<"Case "<<i+1<<":"<<endl;
        cin >> command ;
        pages[0] = "http://www.lightoj.com/";
        current_index = 0;
        end_index = 0;

        while(command != "QUIT")
        {
            if(command == "BACK")
            {
                if(current_index - 1 >=0)
                {
                    cout << pages[current_index-1]<<endl;
                    current_index--;
                }
                else
                {
                    cout << "Ignored"<<endl;
                }
            }
            else if(command == "FORWARD")
            {
                if(current_index +1 <= end_index)
                {
                    cout << pages[current_index + 1]<<endl;
                    current_index++;
                }
                else
                {
                    cout << "Ignored" << endl;
                }
            }
            else if(command == "VISIT")
            {
                cin >> go_page;
                pages[current_index+1] = go_page;
                current_index++;
                end_index = current_index;
                cout << pages[current_index]<<endl;
            }
            cin >> command;
        }
    }
    return 0;
}
