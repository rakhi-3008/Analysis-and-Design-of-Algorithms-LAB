#include <iostream>
using namespace std;

#define MAX 20
#define INF 999

int n;
int cost[MAX][MAX], dist[MAX], visited[MAX];

// Find vertex with minimum distance
int findMin()
{
    int min = INF, pos = -1;

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            pos = i;
        }
    }

    return pos;
}

void dijkstra(int source)
{
    for(int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        dist[i] = cost[source][i];
    }

    visited[source] = 1;
    dist[source] = 0;

    for(int i = 1; i <= n-1; i++)
    {
        int u = findMin();
        visited[u] = 1;

        for(int v = 1; v <= n; v++)
        {
            if(visited[v] == 0 && dist[v] > dist[u] + cost[u][v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
}

// Print result
void printDist(int source)
{
    cout << "\nShortest distance from vertex " << source << ":\n";

    for(int i = 1; i <= n; i++)
    {
        cout << source << " -> " << i << " = " << dist[i] << endl;
    }
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost adjacency matrix:\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int source = 1;   // starting vertex
    dijkstra(source);

    printDist(source);

    return 0;
}