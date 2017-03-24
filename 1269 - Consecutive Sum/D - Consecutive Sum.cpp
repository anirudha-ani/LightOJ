#include <bits/stdc++.h>

using namespace std;

struct node
{
    int counter;
    node *zero;
    node *one ;

    node()
    {
        counter = 0 ;
        zero = NULL;
        one = NULL;
    }
};

void Clear(node *root)
{
    if(root -> zero != NULL)
    {
        Clear(root->zero);
    }
    if(root -> one != NULL)
    {
        Clear(root->one);
    }
    delete root;
}

void insert_value(node *root , int value )
{
    node *currentNode = root;
    int currentBit;
    for(int i = 31 ; i >= 0 ; i-- )
    {
        currentBit = 1&(value>>i);

        if(currentBit == 1)
        {
            if(currentNode->one != NULL)
            {
                currentNode = currentNode->one;
                currentNode->counter++;
            }
            else
            {
                node *newNode = new node;

                currentNode->one = newNode;
                currentNode = currentNode->one;
                currentNode->counter++;
            }
        }
        else if(currentBit == 0)
        {
            if(currentNode->zero != NULL)
            {
                currentNode = currentNode->zero;
                currentNode->counter++;
            }
            else
            {
                node *newNode = new node;

                currentNode->zero = newNode;
                currentNode = currentNode->zero;
                currentNode->counter++;
            }
        }
    }
}

int findMaxValue(node *root , int value)
{
    node *currentNode = root;
    int ans =  0 ;
    int neededBit;
    for(int i = 31 ; i>= 0 ; i--)
    {
        neededBit = (1 & (value >> i))^1;
        ans = ans << 1;
        if(neededBit == 1)
        {
            //cout << "i = " <<i<< endl;
            if(currentNode->one != NULL && currentNode->one->counter > 0)
            {
               // cout << 1 ;
                currentNode = currentNode->one;
                ans += 1;
            }
            else
            {
                //cout << 0;
                currentNode = currentNode->zero;
            }
        }
        else if(neededBit == 0)
        {
            //cout << "i = " <<i<< endl;
            if(currentNode->zero != NULL && currentNode->zero->counter > 0)
            {
                //cout << 0;
                currentNode = currentNode->zero;
            }
            else
            {
                //cout << 1;
                currentNode = currentNode->one;
                ans+=1;
            }
        }
    }
    return ans ;
}

int findMinValue(node *root , int value)
{
    node *currentNode = root;
    int ans =  0 ;
    int neededBit;
    for(int i = 31 ; i>= 0 ; i--)
    {
        neededBit = (1 & (value >> i));
        ans = ans << 1;
        if(neededBit == 1)
        {
            if(currentNode->one != NULL && currentNode->one->counter > 0)
            {
               // cout << 1 ;
                currentNode = currentNode->one;
                ans += 1;
            }
            else
            {
                //cout << 0;
                currentNode = currentNode->zero;
            }
        }
        else if(neededBit == 0)
        {
            //cout << "i = " <<i<< endl;
            if(currentNode->zero != NULL && currentNode->zero->counter > 0)
            {
                //cout << 0;
                currentNode = currentNode->zero;
            }
            else
            {
                //cout << 1;
                currentNode = currentNode->one;
                ans+=1;
            }
        }
    }
    return ans ;
}

int main()
{
    int T , n , xorValue , minValue , maxValue , value;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d", &n);

        node *root = new node ;

        maxValue = 0 ;
        minValue = 99999999;
        xorValue = 0;

        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &value);

            xorValue = xorValue ^ value ;

            if(j== 0)
            {
                maxValue = value;
                minValue = value ;
                insert_value(root , xorValue);
                insert_value(root , 0);
            }
            else
            {
                int x =  findMaxValue(root , xorValue)^xorValue;
                int y =   findMinValue(root , xorValue)^xorValue;
                //cout << x << ":::" << y << endl;
                maxValue = max(maxValue , x);
                minValue = min(minValue , y);
                insert_value(root , xorValue);
            }



        }
        printf("Case %d: %d %d\n", i+1 , maxValue ,minValue);
        Clear(root);
    }
    return 0;
}
