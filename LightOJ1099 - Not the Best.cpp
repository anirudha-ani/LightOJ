#include <bits/stdc++.h>

using namespace std;

/**
Solution of finding second best path using Dijkstra
Problem Link - http://lightoj.com/volume_showproblem.php?problem=1099
**/

#define maxDistance 1000000000000



struct nodeDistance
{
    int index ;
    int distance ;
    int secondDistance ;
    nodeDistance(int givenIndex , int givenDistance , int givensecondDistance)
    {
        index = givenIndex;
        distance = givenDistance ;
        secondDistance = givensecondDistance ;
    }

    bool operator < (const nodeDistance &another) const
    {
        if(distance == another.distance)
        {
            return secondDistance > another.secondDistance;
        }
        return distance > another.distance;
    }
};


vector <nodeDistance> adjacencyList[100005] ;


int main()
{
    int T ;

    scanf("%d" , &T);

    for(int k = 0 ; k < T ; k++)
    {
        int n , m ;
        int node1 , node2 , distance;
        map <int  , int> found;

        scanf("%d %d", &n , &m);

        long long int minDistance[100005];
        long long int secondMinDistance[100005];


        for(int i = 0 ; i < 100005 ; i++)
        {
            minDistance[i] = maxDistance;
            secondMinDistance[i] = maxDistance ;

            adjacencyList[i].clear();
        }


        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d %d %d", &node1 , &node2 , &distance);
            found[node1] = 1;
            found[node2] = 1;
            adjacencyList[node1].push_back(nodeDistance(node2 , distance , distance));
            adjacencyList[node2].push_back(nodeDistance(node1 , distance , distance));
        }




            priority_queue <nodeDistance> Dijkstra ;

            Dijkstra.push(nodeDistance(1, 0 , maxDistance));

            minDistance[1] = 0;
            secondMinDistance[1] = maxDistance ;

            while(Dijkstra.empty() != true)
            {
                nodeDistance currentNode = Dijkstra.top();

                Dijkstra.pop();

                int adjacencyNodeNumbers = adjacencyList[currentNode.index].size();

                for(int i = 0 ; i < adjacencyNodeNumbers ; i++)
                {
                    long long int newDistance = adjacencyList[currentNode.index][i].distance + minDistance[currentNode.index] ;
                    long long int new2ndDistance = adjacencyList[currentNode.index][i].distance + secondMinDistance[currentNode.index];
                    long long int prevDis =  minDistance[adjacencyList[currentNode.index][i].index] ;
                    long long int prev2ndDistance = secondMinDistance[adjacencyList[currentNode.index][i].index];

                    long long int tempPrevDistance = prevDis;
                    long long int tempPrev2ndDistance = prev2ndDistance;

                    vector<long long int> DisT ;

                    DisT.push_back(newDistance);
                    DisT.push_back(new2ndDistance);
                    DisT.push_back(prevDis);
                    DisT.push_back(prev2ndDistance);

                    sort(DisT.begin() , DisT.end());

                    prevDis = DisT[0];
                    if(DisT[1] != DisT[0] )
                    {
                        prev2ndDistance = DisT[1];
                    }
                    else  if(DisT[2] != DisT[0] )
                    {
                        prev2ndDistance = DisT[2];
                    }
                    else
                    {
                        prev2ndDistance = DisT[3];
                    }
                   // int x ;
                    //cin  >> x ;

                    if(prevDis != tempPrevDistance || tempPrev2ndDistance != prev2ndDistance)
                    {
                        minDistance[adjacencyList[currentNode.index][i].index] = prevDis;
                        secondMinDistance[adjacencyList[currentNode.index][i].index] = prev2ndDistance;
                        Dijkstra.push(nodeDistance(adjacencyList[currentNode.index][i].index , prevDis , prev2ndDistance));
                    }

                }
            }

            printf("Case %d: %lld\n",k+1 , secondMinDistance[n] );





    }


    return 0;
}
