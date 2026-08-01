/*
Program: Kruskal's Minimum Spanning Tree (MST) Algorithm
Language: C

Example Test Case

Input:
Enter number of vertices: 4
Enter number of edges: 5

Enter source, destination and weight:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Output:
Edges in the Minimum Spanning Tree:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10

Minimum Cost of MST = 19
*/

#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src, dest, weight;
};

struct Subset
{
    int parent;
    int rank;
};

// Find with path compression
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Union by rank
void Union(struct Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
    {
        subsets[rootX].parent = rootY;
    }
    else if (subsets[rootX].rank > subsets[rootY].rank)
    {
        subsets[rootY].parent = rootX;
    }
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Sort edges by weight
void sortEdges(struct Edge edges[], int E)
{
    struct Edge temp;

    for(int i = 0; i < E - 1; i++)
    {
        for(int j = 0; j < E - i - 1; j++)
        {
            if(edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter source, destination and weight:\n");

    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    sortEdges(edges, E);

    struct Subset subsets[V];

    for(int i = 0; i < V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int edgeCount = 0;
    int i = 0;
    int totalCost = 0;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while(edgeCount < V - 1 && i < E)
    {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if(x != y)
        {
            printf("%d -- %d == %d\n",
                   nextEdge.src,
                   nextEdge.dest,
                   nextEdge.weight);

            totalCost += nextEdge.weight;
            Union(subsets, x, y);
            edgeCount++;
        }
    }

    printf("\nMinimum Cost of MST = %d\n", totalCost);

    return 0;
}