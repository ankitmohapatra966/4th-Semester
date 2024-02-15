#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10

long long int get_spanning_tree_count_complete(int num_nodes) {
    long long int spanning_tree_count = 1;
    for (int i = 2; i < num_nodes; ++i) {
        spanning_tree_count *= num_nodes;
    }
    return spanning_tree_count;
}

long long int get_spanning_tree_count(int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    int degree[MAX_NODES] = {0};
    int laplacian[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            if (i != j) {
                degree[i] += graph[i][j];
                laplacian[i][j] = -graph[i][j];
            }
        }
        laplacian[i][i] = degree[i];
    }

    long long int determinant = 1;
    for (int i = 0; i < num_nodes - 1; ++i) {
        for (int j = i + 1; j < num_nodes; ++j) {
            int factor = laplacian[j][i] / laplacian[i][i];
            for (int k = 0; k < num_nodes; ++k) {
                laplacian[j][k] -= factor * laplacian[i][k];
            }
        }
        determinant *= laplacian[i][i];
    }

    return determinant;
}

int getNumEdges(int adjMatrix[][MAX_NODES], int n) {
    int numEdges = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            numEdges += adjMatrix[i][j];
        }
    }
    return numEdges;
}

bool isComplete(int adjMatrix[][MAX_NODES], int n) {
    int maxEdges = n * (n - 1) / 2;
    return getNumEdges(adjMatrix, n) == maxEdges;
}

int main() {
    int num_nodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    if (num_nodes <= 0 || num_nodes > MAX_NODES) {
        fprintf(stderr, "Invalid number of nodes. Must be between 1 and %d\n", MAX_NODES);
        return 1;
    }

    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    bool isCompleteGraph = isComplete(graph, num_nodes);
    printf("Is the graph complete? %s\n", (isCompleteGraph ? "Yes" : "No"));

    long long int spanning_count;
    if (isCompleteGraph) {
        spanning_count = get_spanning_tree_count_complete(num_nodes);
    } else {
        spanning_count = get_spanning_tree_count(graph, num_nodes);
    }

    printf("Number of spanning trees: %lld\n", spanning_count);

    return 0;
}
