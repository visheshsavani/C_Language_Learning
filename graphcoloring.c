#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool **graph;
int V;

void freeGraph() {
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
}

void showColors(int color[]) {
    printf("Assigned Colors are:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
}

bool isValid(int v, int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoring(int colors, int color[], int vertex) {
    if (vertex == V)
        return true;
    for (int col = 1; col <= colors; col++) {
        if (isValid(vertex, color, col)) {
            color[vertex] = col;
            if (graphColoring(colors, color, vertex + 1))
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

bool checkSolution(int m) {
    int *color = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        color[i] = 0;
    if (graphColoring(m, color, 0) == false) {
        printf("Solution does not exist.\n");
        free(color);
        return false;
    }
    showColors(color);
    free(color);
    return true;
}

int main() {
    int colors;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Dynamically allocate memory for the graph
    graph = (bool **)malloc(V * sizeof(bool *));
    for (int i = 0; i < V; i++) {
        graph[i] = (bool *)malloc(V * sizeof(bool));
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &colors);

    checkSolution(colors);

    // Free dynamically allocated memory
    freeGraph();

    return 0;
}
