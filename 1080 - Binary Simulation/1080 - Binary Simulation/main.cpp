//
//  main.cpp
//  1080 - Binary Simulation
//
//  Created by Anirudha Paul on 4/20/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int MAX  = 100005;
int data[100005];
int tree[100005];

int query(int range);
void update(int index , int value);

int main(int argc, const char * argv[])
{
    int case_no , string_length , i , j , query_no , start , end , index , output ;

    string input;

    char query_type;

    scanf("%d", &case_no);

    for (i = 0 ; i < case_no; i++)
    {
        printf("Case %d:\n", i+1);
        memset(tree, 0, sizeof(tree));

        cin >> input;

        string_length = input.length();
        MAX = string_length;

        for (j = 0; j < string_length; j++)
        {
            data[j] = input[j] - '0';
        }

        scanf("%d", &query_no);

        for (j = 0 ; j < query_no; j++)
        {
            getchar();
            scanf("%c", &query_type);

            if(query_type == 'I')
            {
                scanf("%d %d", &start , &end);

                update(start, 1);
                update(end + 1 , -1);
            }
            else if(query_type == 'Q')
            {
                scanf("%d" , &index);

                //printf("Main string::: %d \n Interchanged::: %d times\n", data[index-1] , query(index));

                output = data[index - 1] ^ (query(index) % 2);

                printf("%d\n", output);
            }
        }
    }

    return 0;
}


int query(int range)
{
    int summation = 0 , position;

    while(range>0)
    {
        position = (range&(-range));
        summation += tree[range];

        range -= position;
    }

    return summation;
}

void update(int index , int value)
{
    int position;
    while (index <= MAX)
    {
        tree[index] += value;

        position = (index & (-index));
        index += position;
    }
}
