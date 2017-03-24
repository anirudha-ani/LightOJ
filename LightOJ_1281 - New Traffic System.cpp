#include <bits/stdc++.h>

/**Dijkstra Code For Some Restricted Path
//Link - http://lightoj.com/volume_showproblem.php?problem=1281
**/
using namespace std;

#define maxDistance 1000000000000



struct nodeDistance
{
    int index ;
    int distance ;
    int pathUsed ;
    nodeDistance(int givenIndex , int givenDistance , int path)
    {
        index = givenIndex;
        distance = givenDistance ;
        pathUsed = path ;
    }

    bool operator < (const nodeDistance &another) const
    {
        return distance > another.distance;
    }
};


vector <nodeDistance> adjacencyList[20005] ;
long long int minDistance[15][20005];

int main()
{

    int T ;

    scanf("%d", &T);

    for(int test_case = 1 ; test_case <= T ; test_case++)
    {
        int n , m , k , d ;
        int node1 , node2 , distance;
        map <int  , int> found;

        scanf("%d %d %d %d", &n , &m , &k , &d);



        for(int i = 0 ; i < 20005 ; i++)
        {
            for(int j = 0 ; j < 15 ; j++)
            {
                minDistance[j][i] = maxDistance;
            }

            adjacencyList[i].clear();
        }

        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d %d %d", &node1 , &node2 , &distance);
            found[node1] = 1;
            found[node2] = 1;
            adjacencyList[node1].push_back(nodeDistance(node2 , distance , 0));
        }

        for(int i = 0 ; i < k ; i++)
        {
            scanf("%d %d %d", &node1 , &node2 , &distance);
            found[node1] = 1;
            found[node2] = 1;
            adjacencyList[node1].push_back(nodeDistance(node2 , distance , 1));
        }

        if(found[0] == 0 || found[n-1] == 0)
        {
            printf("Case %d: Impossible\n", test_case);
        }
        else
        {
            priority_queue <nodeDistance> Dijkstra ;

            Dijkstra.push(nodeDistance(0, 0 , 0));
            minDistance[0][0] = 0;

            while(Dijkstra.empty() != true)
            {
                nodeDistance currentNode = Dijkstra.top();
                Dijkstra.pop();
                //cout << "::" << currentNode.index << " " << currentNode.distance <<" " <<  currentNode.pathUsed << endl ;
                if(currentNode.pathUsed > d)
                {
                    continue;
                }

                int adjacencyNodeNumbers = adjacencyList[currentNode.index].size();

                for(int i = 0 ; i < adjacencyNodeNumbers ; i++)
                {

                    long long int newDistance = adjacencyList[currentNode.index][i].distance + minDistance[currentNode.pathUsed][currentNode.index] ;

                    long long int prevDis =  minDistance[currentNode.pathUsed+adjacencyList[currentNode.index][i].pathUsed][adjacencyList[currentNode.index][i].index] ;
                   // int x ;
                    //cin  >> x ;
                    if(newDistance < prevDis && (currentNode.pathUsed+adjacencyList[currentNode.index][i].pathUsed) <= d)
                    {
                        minDistance[currentNode.pathUsed+adjacencyList[currentNode.index][i].pathUsed][adjacencyList[currentNode.index][i].index] = newDistance;
                        Dijkstra.push(nodeDistance(adjacencyList[currentNode.index][i].index , newDistance ,currentNode.pathUsed+adjacencyList[currentNode.index][i].pathUsed));
                    }
                }
            }
            long long int ans = maxDistance;
            for(int i = 0 ; i <= d ; i++)
            {
                ans = min(ans , minDistance[i][n-1]);
            }
            if(ans == maxDistance)
            {
                printf("Case %d: Impossible\n", test_case);
            }
            else
            {
                printf("Case %d: %lld\n", test_case ,ans );
            }
        }

    }

    return 0;
}
