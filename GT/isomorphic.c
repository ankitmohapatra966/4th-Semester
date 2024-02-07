#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void printAdjacencyList(int graph[MAX_VERTICES][MAX_VERTICES], int V);
bool isIsomorphic(int graph1[MAX_VERTICES][MAX_VERTICES], int graph2[MAX_VERTICES][MAX_VERTICES], int V);
void calculateDegree(int graph[MAX_VERTICES][MAX_VERTICES], int V, int degree[]);
void sortArray(int arr[], int n);
int calculateEdges(int graph[MAX_VERTICES][MAX_VERTICES], int V);
bool areDegreeSequencesEqual(int degree1[], int degree2[], int V);
bool areCycleLengthsEqual(int graph[MAX_VERTICES][MAX_VERTICES], int V);

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph1[MAX_VERTICES][MAX_VERTICES], graph2[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix for the first graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph1[i][j]);
        }
    }
    printf("Enter the adjacency matrix for the second graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph2[i][j]);
        }
    }
    printf("\nAdjacency list of edges for the first graph:\n");
    printAdjacencyList(graph1, V);
    printf("\nAdjacency list of edges for the second graph:\n");
    printAdjacencyList(graph2, V);

    if (isIsomorphic(graph1, graph2, V)) {
        printf("\nThe graphs are isomorphic.\n");
    } else {
        printf("\nThe graphs are not isomorphic.\n");
    }

    return 0;
}

void printAdjacencyList(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: ", i + 1);
        int count = 0;
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                printf("%d", j + 1);
                count++;
                if (count < V) {
                    printf("-> ");
                }
            }
        }
        printf("\n");
    }
}

bool isIsomorphic(int graph1[MAX_VERTICES][MAX_VERTICES], int graph2[MAX_VERTICES][MAX_VERTICES], int V) {
    int degree1[MAX_VERTICES] = {0};
    int degree2[MAX_VERTICES] = {0};

    calculateDegree(graph1, V, degree1);
    calculateDegree(graph2, V, degree2);

    sortArray(degree1, V);
    sortArray(degree2, V);

    int edges1 = calculateEdges(graph1, V);
    int edges2 = calculateEdges(graph2, V);

    bool degreeSequencesEqual = areDegreeSequencesEqual(degree1, degree2, V);
    bool cycleLengthsEqual = areCycleLengthsEqual(graph1, V) == areCycleLengthsEqual(graph2, V);
    if (V == V && edges1 == edges2 && degreeSequencesEqual && cycleLengthsEqual) {
        return true;
    }

    return false;
}

// Function to calculate the degree of each vertex in a graph
void calculateDegree(int graph[MAX_VERTICES][MAX_VERTICES], int V, int degree[]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                degree[i]++;
            }
        }
    }
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int calculateEdges(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int edges = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            edges += graph[i][j];
        }
    }
    return edges;
}

bool areDegreeSequencesEqual(int degree1[], int degree2[], int V) {
    for (int i = 0; i < V; i++) {
        if (degree1[i] != degree2[i]) {
            return false;
        }
    }
    return true;
}

bool areCycleLengthsEqual(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    return true;
}
