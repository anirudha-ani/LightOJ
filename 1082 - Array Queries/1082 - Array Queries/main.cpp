//
//  main.cpp
//  1082 - Array Queries
//
//  Created by Anirudha Paul on 4/12/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

void buildSegmentTree( int array[] , int tree [] , int node , int begin , int end);
int query(int array[] , int tree [] , int node , int begin , int end, int i , int j);
int findMinimum(int array[] , int tree [] , int node , int begin , int end, int i , int j);

int main(int argc, const char * argv[])
{
    int T ;
    
    scanf("%d", &T);
    
    for(int i = 0 ; i < T ; i++)
    {
        string line;
        getline(cin,line );
        
        int n , q , node = 1;
        
        scanf("%d %d", &n , &q);
        
        int *array = new int [n+1];
        int *tree = new int [(n+1)*3];
        
        for( int x = 1 ; x <= n ; x++)
        {
            int a ;
            
            scanf("%d" , &a);
            array [ x ] = a;
        }
        
        buildSegmentTree(array , tree , node , 1 , n);
        
        
        printf("Case %d:\n", i+1);
        for (int i = 0 ; i < q ; i ++)
        {
            int a , b;
            scanf("%d %d" , &a , &b);
            printf("%d\n", query(array ,tree,node , 1 , n , a , b));
            
        }
        
        
    }
    
    return 0;
}

//Main algorithm of building this tree is every node contains the minimum value of his child
//It maintains the segment tree structure because every node represents the minimum value of
//a particular range

void buildSegmentTree( int array[] , int tree [] , int node , int begin , int end)  {
    
    if (begin == end)
    {
        tree [node] = array [begin];
    }
    else
    {
        int left  = node * 2 ;
        int right = node * 2 + 1 ;
        int mid = (begin + end) / 2 ;
        
        buildSegmentTree(array, tree, left, begin, mid);
        buildSegmentTree(array, tree, right, mid + 1, end);
        
        if(tree[left] <= tree [right])
        {
              tree[node] = tree [left];
        }
        else
        {
            tree[node] = tree [right];
        }
    }
    
}

//the task is to find the minimum value of a given range

//1st if else condition checks if the range is out of bound . then to avoid conflict it
//returns -1 so that the following algorithm can understand the return value is not a valid
//one so it ignores it .


//2nd if else returns if the node range is totally in the given range
//then it simply returns the value

//3rd if else compare and process all returned values and then return the minimum one among them

int query(int array[] , int tree [] , int node , int begin , int end, int i , int j)
{
    if(j < begin || i > end)
    {
        return -1;
    }
    
    else if (begin >= i && end <=j)
    {
        return tree[node];
    }
    else
    {
        int left  = node * 2 ;
        int right = node * 2 + 1 ;
        int mid = (begin + end) / 2 ;
        
        int leftAns = query(array, tree, left, begin, mid, i, j);
        int rightAns = query(array, tree, right, mid + 1, end, i, j);
        
        if (leftAns == -1)
        {
            return rightAns;
        }
        else if (rightAns == -1)
        {
            return leftAns ;
        }
        else if (leftAns <= rightAns)
        {
            return leftAns;
        }
        else
        {
            return rightAns;
        }
    }
    
}

