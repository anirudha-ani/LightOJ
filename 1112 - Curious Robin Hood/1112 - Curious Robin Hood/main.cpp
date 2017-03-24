//
//  main.cpp
//  1112 - Curious Robin Hood
//
//  Created by Anirudha Paul on 4/5/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

void buildSegmentTree( int array[] , int tree [] , int node , int begin , int end);
int query(int array[] , int tree [] , int node , int begin , int end, int i , int j);
void elementUpdate(int array[] , int tree [] , int node , int begin , int end, int i , int cValue);


int main(int argc, const char * argv[])
{
    
    int T;
    
    scanf("%d", &T);
    
    for (int x = 0 ; x < T ; x++)
    {
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
        
        printf("Case %d:\n",x+1);
        
        for (int x = 0 ; x < q; x++)
        {
            int operation , i , v ,j ;
            scanf("%d" , &operation);
            
            switch(operation)
            {
                case 1 :
                {
                    scanf("%d", &i);
                    int Value = query(array, tree , node, 1, n , i+1, i+1);
                    int cValue = -1 * Value;
                    elementUpdate(array, tree, 1, 1, n, i+1, cValue);
                    printf("%d\n",Value);
                    break;
                }
                    
                case 2 :
                {
                    scanf("%d %d", &i , &v);
                    elementUpdate(array, tree, 1, 1, n, i+1, v);
                    break;
                }
                    
                case 3 :
                {
                    scanf("%d %d", &i , &j);
                    printf ("%d\n", query(array, tree , node, 1, n , i+1, j+1));
                }


            }
            
        }
        delete []array;
        delete []tree;
    }
   
    return 0;
}

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
        
        tree[node] = tree [left] + tree [right];
    }
}

int query(int array[] , int tree [] , int node , int begin , int end, int i , int j)
{
    if(j < begin || i > end)
    {
        return 0;
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
        
        return leftAns + rightAns;
    }
    
}

void elementUpdate(int array[] , int tree [] , int node , int begin , int end, int i , int cValue)
{
    if (i < begin  || i > end)
    {
        return ;
    }
    else if(begin == end && end == i)
    {
        tree[node] = tree [node] + cValue;
    }
    else
    {
        int left  = node * 2 ;
        int right = node * 2 + 1 ;
        int mid = (begin + end) / 2 ;
        
        if ( i > mid )
        {
            tree[node] = tree [node] + cValue;
            elementUpdate(array, tree, right, mid +1, end, i, cValue);
        }
        
        else
        {
            tree[node] = tree [node] + cValue;
            elementUpdate(array, tree, left , begin, mid, i, cValue);
        }
    }
    
}
