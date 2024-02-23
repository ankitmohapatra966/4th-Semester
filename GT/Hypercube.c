#include <stdio.h>

void findAdjacentVertices(int vertex, int dimension, int *adjacentVertices) {
    for (int i = 0; i < dimension; ++i) {
        int adjacentVertex = vertex ^ (1 << i); 
        adjacentVertices[i] = adjacentVertex;
    }
}

int main() {
    int dimension;
    printf("Enter the dimension of the hypercube: ");
    scanf("%d", &dimension);

    int totalVertices = 1 << dimension;
    int totalEdges = dimension * totalVertices / 2;

    printf("Total number of vertices: %d\n", totalVertices);
    printf("Total number of edges: %d\n", totalEdges);

    int vertex;
    do {
        printf("Enter a vertex (0 to %d): ", totalVertices - 1);
        scanf("%d", &vertex);

        if (vertex < 0 || vertex >= totalVertices) {
            printf("Invalid vertex. Please enter a valid vertex within the range.\n");
        }
    } while (vertex < 0 || vertex >= totalVertices);

    int adjacentVertices[dimension];
    findAdjacentVertices(vertex, dimension, adjacentVertices);

    printf("Adjacent vertices of vertex %d: ", vertex);
    for (int i = 0; i < dimension; ++i) {
        printf("%d ", adjacentVertices[i]);
    }
    printf("\n");

    return 0;
}
