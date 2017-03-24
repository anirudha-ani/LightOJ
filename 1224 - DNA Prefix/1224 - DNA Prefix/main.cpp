//
//  main.cpp
//  1224 - DNA Prefix
//
//  Created by Anirudha Paul on 8/13/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>


using namespace std;

int maxNumber;

struct node
{
    node *dataTable[4];
    int counter ;
    bool finish ;
    int depth ;
    
    node()
    {
        counter = 0;
        finish = false;
        depth = 0;
        
        for(int i = 0 ; i < 4 ; i++)
        {
            dataTable[i] = NULL;
        }
    }
    
};

void Clear(node *root)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        if(root->dataTable[i] != NULL)
        {
            Clear(root->dataTable[i]);
        }
    }
    delete root;
}

void insert(string input , node *root)
{
    int length = input.length();
    int index = 0;
    
    node *currNode = root;
    
    for(int i = 0 ; i < length ; i++)
    {
        if(input[i] == 'A')
        {
            index = 0 ;
        }
        else if(input[i] == 'C')
        {
            index = 1 ;
        }
        else if(input[i] == 'G')
        {
            index = 2;
        }
        else if(input[i] == 'T')
        {
            index = 3;
        }
        
        if(currNode->dataTable[index] != NULL)
        {
            currNode = currNode->dataTable[index];
            currNode->counter++;
            maxNumber = max(maxNumber , currNode->counter * currNode->depth);
            
        }
        else
        {
            node *newNode = new node ;
            
            newNode->depth = currNode->depth + 1;
            currNode->dataTable[index] = newNode;
            
            currNode = currNode->dataTable[index];
            currNode->counter++;
            maxNumber = max(maxNumber , currNode->counter * currNode->depth);
        }
        
    }
}

int main(int argc, const char * argv[])
{
    int T , n ;
    
    string input ;
    
    scanf("%d", &T);
    
    for(int i = 0 ; i < T ; i++)
    {
        node *root = new node ;
        maxNumber = 0;
        
        scanf("%d", &n);
        
        for(int j = 0 ; j < n ; j++)
        {
            cin >> input ;
            insert(input, root);
        }
        printf("Case %d: %d\n", i+1 , maxNumber);
        Clear(root);
    }
    
    return 0;
}
