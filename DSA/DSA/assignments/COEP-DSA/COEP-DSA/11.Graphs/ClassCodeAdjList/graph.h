// Define a structure for the adjacency list node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;


Node* createNode(int dest);
void initGraph(Graph* graph, int vertices);
void addEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);

