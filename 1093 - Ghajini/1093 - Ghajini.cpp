#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T  , n , d , input , currentIndex , currentMax , currentMin , bestDifference ;

    scanf("%d",&T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d", &n , &d);

        currentIndex = 0;
        currentMax = -1;
        currentMin = 9999999;
        bestDifference = 0 ;

        deque <int> maxQueue ;
        deque <int> maxIndex ;
        deque <int> minQueue;
        deque <int> minIndex ;

        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &input);
            currentIndex++;

            if(maxQueue.empty()!=true)
            {
                while(maxQueue.empty()!=true && maxQueue.back()<input)
                {
                    maxQueue.pop_back();
                    maxIndex.pop_back();
                }
                while(maxQueue.empty()!=true && (currentIndex - maxIndex.front()) >= d)
                {
                    maxQueue.pop_front();
                    maxIndex.pop_front();
                }
                maxQueue.push_back(input);
                maxIndex.push_back(currentIndex);
            }
            else
            {
                maxQueue.push_back(input);
                maxIndex.push_back(currentIndex);
            }
            if(minQueue.empty()!=true)
            {
                while(minQueue.empty()!=true && minQueue.back()>input)
                {
                    minQueue.pop_back();
                    minIndex.pop_back();
                }
                while(minQueue.empty()!=true && (currentIndex - minIndex.front()) >= d)
                {
                    minQueue.pop_front();
                    minIndex.pop_front();
                }
                minQueue.push_back(input);
                minIndex.push_back(currentIndex);
            }
            else
            {
                minQueue.push_back(input);
                minIndex.push_back(currentIndex);
            }
            //cout << maxQueue.front() << " " << minQueue.front() << endl ;
            bestDifference = max(bestDifference , maxQueue.front() - minQueue.front());
        }
        printf("Case %d: %d\n", i+1 , bestDifference);
    }
    return 0;
}
