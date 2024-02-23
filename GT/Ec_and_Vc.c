#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int V;
    int **adj;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            graph->adj[i][j] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int v, int w) {
    graph->adj[v][w] = 1;
    graph->adj[w][v] = 1;
}

void vertexConnectivityUtil(int u, int disc[], int low[], int parent[], bool ap[], struct Graph* graph) {
    static int time = 0;
    int children = 0;

    disc[u] = low[u] = ++time;

    for (int v = 0; v < graph->V; v++) {
        if (graph->adj[u][v]) {
            if (disc[v] == -1) {
                children++;
                parent[v] = u;
                vertexConnectivityUtil(v, disc, low, parent, ap, graph);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (parent[u] == -1 && children > 1)
                    ap[u] = true;

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent[u])
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
}

void vertexConnectivity(struct Graph* graph) {
    int disc[MAX_VERTICES], low[MAX_VERTICES], parent[MAX_VERTICES];
    bool ap[MAX_VERTICES];

    for (int i = 0; i < graph->V; i++) {
        disc[i] = -1;
        low[i] = -1;
        parent[i] = -1;
        ap[i] = false;
    }

    for (int i = 0; i < graph->V; i++)
        if (disc[i] == -1)
            vertexConnectivityUtil(i, disc, low, parent, ap, graph);

    int count = 0;
    for (int i = 0; i < graph->V; i++)
        if (ap[i])
            count++;

    printf("Vertex Connectivity: %d\n", count);
}

bool isEdgeConnected(int u, int v, struct Graph* graph) {
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    int stack[graph->V], top = -1;
    stack[++top] = u;

    while (top != -1) {
        int current = stack[top--];
        visited[current] = true;

        if (current == v)
            return true;

        for (int neighbor = 0; neighbor < graph->V; neighbor++) {
            if (graph->adj[current][neighbor] && !visited[neighbor])
                stack[++top] = neighbor;
        }
    }

    free(visited);
    return false;
}

void edgeConnectivity(struct Graph* graph) {
    int minConnectivity = graph->V - 1;

    for (int u = 0; u < graph->V; ++u) {
        for (int v = 0; v < graph->V; v++) {
            if (graph->adj[u][v]) {
                if (isEdgeConnected(u, v, graph)) {
                    int size_u = 0, size_v = 0;
                    for (int i = 0; i < graph->V; i++) {
                        if (graph->adj[u][i])
                            size_u++;
                        if (graph->adj[v][i])
                            size_v++;
                    }
                    minConnectivity = (minConnectivity < (size_u < size_v ? size_u : size_v)) ? minConnectivity : (size_u < size_v ? size_u : size_v);
                }
            }
        }
    }

    printf("Edge Connectivity: %d\n", minConnectivity);
}

int main() {
    
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);
    printf("Enter the edges (pairs of vertices, -1 to stop):\n");
    int v, w;
    while (scanf("%d %d", &v, &w)) {
        if (v == -1 || w == -1)
            break;
        addEdge(graph, v, w);
    }
    vertexConnectivity(graph);
    edgeConnectivity(graph);

    return 0;
}
