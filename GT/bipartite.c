#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];

int isBipartite(int graph[][MAX_VERTICES], int V) {
    int color[MAX_VERTICES];
    for (int i = 0; i < V; i++)
        color[i] = -1;

    color[0] = 1;

    for (int u = 0; u < V; u++) {
        if (graph[u][u] == 1) 
            return 0;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && color[v] == -1)
                color[v] = 1 - color[u];
            else if (graph[u][v] && color[v] == color[u])
                return 0;
        }
    }
    return 1;
}

int isCompleteBipartite(int graph[][MAX_VERTICES], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if ((graph[i][j] == 0 && graph[j][i] == 0) || (graph[i][j] == 1 && graph[j][i] == 1))
                return 1;
        }
    }
    return 0;
}

void printAdjacencyList(int graph[][MAX_VERTICES], int V) {
    printf("Adjacency List:\n");
    for (int i = 0; i < V; i++) {
        printf("%d -> ", i);
        int first = 1;
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                if (!first) {
                    printf(", ");
                }
                printf("%d", j);
                first = 0;
            }
        }
        printf("\n");
    }
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (vertex pairs):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printAdjacencyList(graph, V);

    if (isBipartite(graph, V))
        printf("The graph is bipartite.\n");
    else
        printf("The graph is not bipartite.\n");

    if (isCompleteBipartite(graph, V))
        printf("The graph is complete bipartite.\n");
    else
        printf("The graph is not complete bipartite.\n");

    return 0;
}
