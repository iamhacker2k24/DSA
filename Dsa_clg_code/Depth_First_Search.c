/*
Program: Depth-First Search (DFS) Graph Traversal Algorithm
Language: C

Example Test Case

Input:
Enter number of vertices: 5

Enter the adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 0
0 1 0 0 0

Enter the starting vertex: 0

Output:
DFS Traversal:
0 1 3 4 2

----------------------------------

Another Test Case

Input:
Enter number of vertices: 4

Enter the adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 0
0 1 0 0

Enter the starting vertex: 2

Output:
DFS Traversal:
2 0 1 3
*/

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int V;

// Recursive DFS function
void DFS(int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for(int i = 0; i < V; i++)
    {
        if(graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for(int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal:\n");
    DFS(start);

    printf("\n");

    return 0;
}