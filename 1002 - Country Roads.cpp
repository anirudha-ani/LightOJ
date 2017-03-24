#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
struct paths
{
    int city;
    int distance ;

    paths(int c  , int d)
    {
        city = c ;
        distance = d ;
    }

    bool operator < (const paths &anotherPath) const
    {
        distance > anotherPath.distance;
    }
};

int main()
{
    int T , n , m , city1 , city2 , distance;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        priority_queue <paths> smallestPath ;
        vector <paths> adjacencyList[505] ;
        int calculatedShortestPath[505];

        for(int j = 0 ; j < 505 ; j++)
        {
            calculatedShortestPath[j] = INF;
        }

        scanf("%d %d", &n , &m );

        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d %d %d", &city1 , &city2 , &distance);

            adjacencyList[city1].push_back(paths(city2 , distance));
            adjacencyList[city2].push_back(paths(city1 , distance));
        }

        int pathStarted ;

        scanf("%d",&pathStarted );

        calculatedShortestPath[pathStarted] = 0 ;

        smallestPath.push(paths(pathStarted , 0));

        while(smallestPath.empty() != true)
        {
            paths currentPath = smallestPath.top();
            smallestPath.pop();

            int connectedNodes = adjacencyList[currentPath.city].size();

            for(int j = 0 ; j < connectedNodes ; j++)
            {
                long long int prevDistance = calculatedShortestPath[adjacencyList[currentPath.city][j].city];
                long long int newDistance = max(currentPath.distance ,adjacencyList[currentPath.city][j].distance);
                if( prevDistance > newDistance)
                {
                    calculatedShortestPath[adjacencyList[currentPath.city][j].city] = newDistance;
                    smallestPath.push(paths(adjacencyList[currentPath.city][j].city, newDistance));
                }
            }
        }

        printf("Case %d:\n", i+1);

        for(int j = 0 ; j < n ; j++)
        {
            if(calculatedShortestPath[j] == INF)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("%d\n", calculatedShortestPath[j]);
            }
        }
    }
    return 0 ;
}
