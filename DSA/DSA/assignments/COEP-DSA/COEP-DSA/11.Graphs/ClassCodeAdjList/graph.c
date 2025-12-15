#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Function to create a new adjacency list node
Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a graph with the specified number of vertices
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;

    // Allocate memory for the adjacency lists
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
}

// Function to add an edge to the graph (undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (if undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the adjacency list of each vertex
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
}


