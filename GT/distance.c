#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int** adjMatrix;
} Graph;

Graph* createGraph(int V);
void addEdge(Graph* graph, int u, int v);
int distanceBetweenVertices(Graph* graph, int src, int dest);
int eccentricityOfVertex(Graph* graph, int v);
int diameter(Graph* graph);
int radius(Graph* graph);
void freeGraph(Graph* graph);

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            graph->adjMatrix[i][j] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

int distanceBetweenVertices(Graph* graph, int src, int dest) {
    int* distance = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++)
        distance[i] = -1;

    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = src;
    distance[src] = 0;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < graph->vertices; v++) {
            if (graph->adjMatrix[u][v] && distance[v] == -1) {
                queue[rear++] = v;
                distance[v] = distance[u] + 1;
            }
        }
    }

    int dist = distance[dest];
    free(distance);
    return dist;
}

int eccentricityOfVertex(Graph* graph, int v) {
    int maxDistance = 0;
    for (int u = 0; u < graph->vertices; u++) {
        if (u != v) {
            int dist = distanceBetweenVertices(graph, u, v);
            if (dist > maxDistance)
                maxDistance = dist;
        }
    }
    return maxDistance;
}

int diameter(Graph* graph) {
    int maxEccentricity = 0;
    for (int v = 0; v < graph->vertices; v++) {
        int ecc = eccentricityOfVertex(graph, v);
        if (ecc > maxEccentricity)
            maxEccentricity = ecc;
    }
    return maxEccentricity;
}

int radius(Graph* graph) {
    int minEccentricity = INT_MAX;
    for (int v = 0; v < graph->vertices; v++) {
        int ecc = eccentricityOfVertex(graph, v);
        if (ecc < minEccentricity)
            minEccentricity = ecc;
    }
    return minEccentricity;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    Graph* graph = createGraph(vertices);

    printf("Enter the edges (vertex pairs):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int src, dest;
    printf("Enter the source vertex for distance calculation: ");
    scanf("%d", &src);

    printf("Enter the destination vertex for distance calculation: ");
    scanf("%d", &dest);

    int distance = distanceBetweenVertices(graph, src, dest);
    printf("Distance between vertices %d and %d: %d\n", src, dest, distance);

    for (int v = 0; v < vertices; v++)
        printf("Eccentricity of vertex %d: %d\n", v, eccentricityOfVertex(graph, v));

    printf("Diameter of the graph: %d\n", diameter(graph));
    printf("Radius of the graph: %d\n", radius(graph));

    freeGraph(graph);

    return 0;
}
