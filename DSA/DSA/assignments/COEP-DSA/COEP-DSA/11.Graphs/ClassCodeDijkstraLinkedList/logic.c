#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists; // Array of pointers to adjacency lists
} Graph;

// Create a new node
Node* createNode(int v, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Initialize the graph
void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    g->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
    }
}

// Add an edge
void addEdge(Graph* g, int src, int dest, int weight) {
    // Add edge from src to dest
    Node* newNode = createNode(dest, weight);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src, weight);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

// Find the vertex with the minimum distance value
int findMin(int* dist, int* visited, int vertices) {
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm using adjacency list
void Dijkstra(Graph* g, int src) {
    int vertices = g->numVertices;
    int dist[vertices];
    int visited[vertices];

    // Initialize distances and visited array
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int u = findMin(dist, visited, vertices);
        if (u == -1) break; // All reachable vertices are processed
        visited[u] = 1;

        Node* temp = g->adjLists[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    // Print the distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    Graph g;
    int vertices = 5;
    initGraph(&g, vertices);

    addEdge(&g, 0, 1, 10);
    addEdge(&g, 0, 4, 5);
    addEdge(&g, 1, 2, 1);
    addEdge(&g, 1, 4, 2);
    addEdge(&g, 2, 3, 4);
    addEdge(&g, 3, 4, 9);
    addEdge(&g, 3, 2, 6);

    printf("Dijkstra's Algorithm from source vertex 0:\n");
    Dijkstra(&g, 0);

    return 0;
}
