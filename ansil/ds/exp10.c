#include <stdio.h>
#include <stdlib.h>

#define MAX 100  


int adj[MAX][MAX];
int visited[MAX];


void DFS(int vertex, int n)
{
    int i;
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[vertex][i] == 1 && !visited[i])
        {
            DFS(i, n);
        }
    }
}


int main()
{
    int n, edges;
    int u, v;
    int startVertex;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

   
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

        visited[i] = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    DFS(startVertex, n);

    return 0;
}
