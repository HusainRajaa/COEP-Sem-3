#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


// Function to initialize the graph with the specified number of vertices
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;  // Initialize with no edges
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // For undirected graph
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0;  // For undirected graph
}

// Function to print the adjacency matrix of the graph
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
}

