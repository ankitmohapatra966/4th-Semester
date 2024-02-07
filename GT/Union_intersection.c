#include <stdio.h>

#define MAX 100

// Function to add an edge to the graph
void addEdge(int adj[][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void displayGraph(int adj[][MAX], int V) {
    for (int i = 0; i < V; ++i) {
        printf("Adjacency list of vertex %d ", i );
        for (int j = 0; j < V; ++j)
            if (adj[i][j] == 1)
                printf("-> %d ",j);
        printf("\n");
    }
}


void graphUnion(int adj1[][MAX], int adj2[][MAX], int unionGraph[][MAX], int V) {
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            unionGraph[i][j] = adj1[i][j] | adj2[i][j];
}

void graphIntersection(int adj1[][MAX], int adj2[][MAX], int intersectionGraph[][MAX], int V) {
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            intersectionGraph[i][j] = adj1[i][j] & adj2[i][j];
}

int main() {
    int V = 5; 
    int adj1[MAX][MAX] = {0};
    int adj2[MAX][MAX] = {0};

    addEdge(adj1, 0, 1);
    addEdge(adj1, 0, 4);
    addEdge(adj1, 1, 2);
    addEdge(adj1, 1, 3);
    addEdge(adj1, 1, 4);
    addEdge(adj1, 2, 3);
    addEdge(adj1, 3, 4);

    addEdge(adj2, 0, 2);
    addEdge(adj2, 0, 4);
    addEdge(adj2, 1, 3);
    addEdge(adj2, 2, 3);
    addEdge(adj2, 3, 4);

    printf("Graph 1:\n");
    displayGraph(adj1, V);

    printf("\nGraph 2:\n");
    displayGraph(adj2, V);

    int unionGraph[MAX][MAX];

    int intersectionGraph[MAX][MAX];~
    printf( "\nUnion of Graph 1 and Graph 2:\n");
    graphUnion(adj1, adj2, unionGraph, V);
    displayGraph(unionGraph, V);

    printf("\nIntersection of Graph 1 and Graph 2:\n");
    graphIntersection(adj1, adj2, intersectionGraph, V);
    displayGraph(intersectionGraph, V);

    return 0;
}