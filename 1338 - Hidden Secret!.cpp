#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int test_case;
    string input1 , input2;
    int map1[26] , map2[26];

    scanf("%d", &test_case);
    getline(cin , input1);
    for(int i = 0 ; i < test_case ; i++)
    {
        getline(cin , input1);
        getline(cin , input2);

        int length1 = input1.length();
        int length2 = input2.length();

        for(int j = 0 ; j < 26 ; j++)
        {
            map1[j] = 0;
            map2[j] = 0;
        }

        for(int j = 0; j<length1 ; j++)
        {
            if(input1[j] >= 'A' && input1[j] <= 'Z' )
            {
                map1[input1[j] + 32 - 'a']++;
            }
            else if(input1[j] >= 'a' && input1[j] <= 'z' )
            {
                map1[input1[j]  - 'a']++;
            }
        }
        for(int j = 0; j<length2 ; j++)
        {
            if(input2[j] >= 'A' && input2[j] <= 'Z' )
            {
                map2[input2[j] + 32 - 'a']++;
            }
            else if(input2[j] >= 'a' && input2[j] <= 'z' )
            {
                map2[input2[j]  - 'a']++;
            }
        }

        bool same = true;
        for(int j = 0 ; j < 26 ; j++)
        {
           if(map1[j] != map2[j])
           {
               //cout << "map 1>>" << map1[j] << " map 2>>" << map2[j] << " j = " << endl;
               same = false;
               break;
           }
        }

        if(same)
        {
            printf("Case %d: Yes\n", i+1);
        }
        else
        {
            printf("Case %d: No\n", i+1);
        }
    }
    return 0;

}
