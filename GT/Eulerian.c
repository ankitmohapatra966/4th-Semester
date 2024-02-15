#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph createGraph(int V) {
    Graph graph;
    graph.vertices = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph.adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

int degree(Graph* graph, int v) {
    int deg = 0;
    for (int i = 0; i < graph->vertices; i++) {
        deg += graph->adjMatrix[v][i];
    }
    return deg;
}

int isConnected(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        int count = 0;
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] == 1)
                count++;
        }
        if (count != 0 && count != 2)
            return 0; // Not connected
    }
    return 1; // Connected
}

int isEulerian(Graph* graph) {
    if (!isConnected(graph))
        return 0; // Not Eulerian

    for (int i = 0; i < graph->vertices; i++) {
        if (degree(graph, i) % 2 != 0)
            return 0; // Not Eulerian
    }
    return 1; // Eulerian
}

void printEulerianCycle(Graph* graph) {
    if (!isEulerian(graph)) {
        printf("The graph is not Eulerian. Cannot find Eulerian cycle.\n");
        return;
    }

    int stack[MAX_VERTICES], top = -1;
    int circuit[MAX_VERTICES], circuit_size = 0;

    stack[++top] = 0;

    while (top >= 0) {
        int u = stack[top];
        int v;

        for (v = 0; v < graph->vertices; v++) {
            if (graph->adjMatrix[u][v] == 1) {
                stack[++top] = v;
                graph->adjMatrix[u][v] = 0;
                graph->adjMatrix[v][u] = 0;
                break;
            }
        }

        if (v == graph->vertices) {
            top--;
            circuit[circuit_size++] = u;
        }
    }

    printf("Eulerian Cycle: ");
    for (int i = circuit_size - 1; i >= 0; i--)
        printf("%d ", circuit[i]);
    printf("\n");
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (vertex pairs):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    if (isEulerian(&graph)) {
        printf("The graph is Eulerian.\n");
        printEulerianCycle(&graph);
    } else {
        printf("The graph is not Eulerian.\n");
    }

    return 0;
}
