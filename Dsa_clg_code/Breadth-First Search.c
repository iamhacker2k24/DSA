/*
Program: Breadth-First Search (BFS) Graph Traversal
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
BFS Traversal:
0 1 2 3 4

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
BFS Traversal:
2 0 1 3
*/

#include <stdio.h>

#define MAX 100

int main()
{
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0;
    int rear = -1;

    int V;

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

    int start;

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // Mark the starting vertex as visited
    visited[start] = 1;
    queue[++rear] = start;

    printf("\nBFS Traversal:\n");

    while(front <= rear)
    {
        int current = queue[front++];

        printf("%d ", current);

        for(int i = 0; i < V; i++)
        {
            if(graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");

    return 0;
}