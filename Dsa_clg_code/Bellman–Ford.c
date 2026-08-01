/*
Program: Bellman-Ford Shortest Path Algorithm
Language: C

Example Test Case

Input:
Enter number of vertices: 5
Enter number of edges: 8

Enter source, destination and weight:
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3

Enter source vertex: 0

Output:
Vertex    Distance from Source
0         0
1         -1
2         2
3         -2
4         1
*/

#include <stdio.h>

#define MAX 100
#define INF 999999

struct Edge
{
    int src;
    int dest;
    int weight;
};

int main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX];

    printf("Enter source, destination and weight:\n");

    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[MAX];

    // Initialize distances
    for(int i = 0; i < V; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;

    // Relax all edges (V-1) times
    for(int i = 1; i <= V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for(int j = 0; j < E; j++)
    {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if(dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("\nGraph contains a negative weight cycle.\n");
            return 0;
        }
    }

    printf("\nVertex\tDistance from Source\n");

    for(int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}