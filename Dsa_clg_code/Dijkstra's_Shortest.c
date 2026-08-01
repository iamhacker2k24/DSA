/*
Program: Dijkstra's Shortest Path Algorithm
Language: C

Example Test Case

Input:
Enter number of vertices: 5

Enter the adjacency matrix:
0 10 0 5 0
10 0 1 2 0
0 1 0 9 4
5 2 9 0 2
0 0 4 2 0

Enter the source vertex: 0

Output:
Vertex   Distance from Source
0        0
1        7
2        8
3        5
4        7
*/

#include <stdio.h>

#define MAX 100
#define INF 999999

// Function to find the vertex with minimum distance
int minDistance(int dist[], int visited[], int V)
{
    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main()
{
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    int dist[MAX];
    int visited[MAX];

    // Initialize distance and visited arrays
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra Algorithm
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);

        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nVertex\tDistance from Source\n");

    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}