/**

Problem Link - http://lightoj.com/volume_showproblem.php?problem=1097
Solving Technique - BIT and Binary Search

General problem I faced - A bit larger array is required otherwise it can not calculate some value from the last of the list
**/

#include <bits/stdc++.h>

using namespace std;

int BITarray[2000000];
vector<int> luckyNumber;
void update(int index , int data)
{
    while(index < 2000000)
    {
        BITarray[index] += data;
        index += (index & (-index));
    }
}

int query(int index)
{
    int ans = 0 ;

    while(index > 0)
    {
        ans += BITarray[index];
        index -= (index & (-index));
    }
    return ans ;
}

int getValueByIndex(int index)
{
    int start = 1 ;
    int finish = 1999999;

    int mid = (start + finish) / 2 ;

    while(start < finish)
    {
        mid = (start + finish) / 2 ;

        if(index <= query(mid))
        {
            finish = mid;
        }
        else
        {
            start = mid + 1 ;
        }
    }
    if(query(mid+1) == index)
    {
        mid++;
    }
    while(query(mid - 1) == index)
    {
        mid--;
    }
    return mid ;
}

void calculateLucyNumber()
{
    for(int i = 1 ; i < 1999999 ; i+=2)
    {
        update(i , 1);
    }

    int index = 2 ;

    int nowDeleting =  getValueByIndex(index);
    int tempDel = nowDeleting ;


    while(nowDeleting < query(1999999))
    {
        vector <int> deleting ;

        int i = 1 ;
        tempDel = nowDeleting;

        while(nowDeleting < query(1999999))
        {
            deleting.push_back(getValueByIndex(nowDeleting));
            i++;
            nowDeleting = tempDel * i ;
        }
        int length = deleting.size();
        for(int j = 0 ; j < length ; j++)
        {

            update(deleting[j], -1);
        }

        index++;
        nowDeleting = getValueByIndex(index);

        if(nowDeleting == tempDel)
        {
            break ;
        }
        else
        {
            tempDel = nowDeleting;
        }
    }
}


int main()
{

    calculateLucyNumber();
    int T ,input;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d", &input);
        printf("Case %d: %d\n", i+1 , getValueByIndex(input));
    }
    return 0 ;
}
