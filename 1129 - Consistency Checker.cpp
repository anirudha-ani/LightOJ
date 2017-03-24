#include <bits/stdc++.h>

using namespace std;

bool globalAns = true;

struct node
{
    bool finish;
    node *addressList[10];
    int counter;

    node()
    {
        finish = false;
        counter = 0;
        for(int i = 0 ; i < 10 ; i++)
        {
            addressList[i] = NULL;
        }
    }
//    ~node()
//    {
//        for(int i = 0 ; i < 10 ; i++)
//        {
//            delete addressList[i];
//        }
//    }
};


void Delete(node *root)
{
    for(int i = 0 ; i < 10 ; i++)
    {
        if(root->addressList[i] != NULL)
        {
            Delete(root->addressList[i]);
        }
    }
    delete root;
}
void buildTree(string input , node *root)
{
    int length = input.length();

    node *current_node = root;

    for(int i = 0 ; i < length ; i++)
    {
        if(current_node->addressList[input[i] - '0'] != NULL)
        {
            current_node = current_node->addressList[input[i] - '0'];
            current_node->counter++;

            if(i == length - 1)
            {
                current_node->finish = true;
                if(current_node->counter > 1)
                {
                    globalAns = false;
                }
            }
        }
        else
        {
            node *newNode = new node;

            if(current_node->finish == true)
            {
                globalAns = false;
            }
            current_node->addressList[input[i] - '0'] = newNode;

            current_node = current_node->addressList[input[i] - '0'];
            current_node->counter++;

            if(i == length - 1)
            {
                current_node->finish = true;
                if(current_node->counter > 1)
                {
                    globalAns = false;
                }
            }
        }
    }
}

int main()
{
    int T;
    int n;
    string input ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        globalAns = true;
        node *root = new node;

        scanf("%d", &n);

        for(int j = 0 ; j < n ; j++)
        {
            cin  >> input;
            buildTree(input , root);
        }
        if(globalAns)
        {
            printf("Case %d: YES\n", i+1);
        }
        else
        {
            printf("Case %d: NO\n", i+1);
        }
        Delete(root);
    }

    return 0 ;
}
