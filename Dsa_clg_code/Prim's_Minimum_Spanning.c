/*
Program: Prim's Minimum Spanning Tree (MST) Algorithm
Language: C

Example Test Case

Input:
Enter number of vertices: 5

Enter the adjacency matrix:
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Output:
Edge      Weight
0 - 1       2
1 - 2       3
1 - 4       5
0 - 3       6

Minimum Cost of MST = 16
*/

#include <stdio.h>

#define MAX 100
#define INF 999999

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[], int V)
{
    int min = INF;
    int minIndex = -1;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
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

    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    // Initialize arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    // Construct MST
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);

        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                mstSet[v] == 0 &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;

    printf("\nEdge\tWeight\n");

    for (int i = 1; i < V; i++)
    {
        printf("%d - %d\t%d\n",
               parent[i],
               i,
               graph[i][parent[i]]);

        totalCost += graph[i][parent[i]];
    }

    printf("\nMinimum Cost of MST = %d\n", totalCost);

    return 0;
}