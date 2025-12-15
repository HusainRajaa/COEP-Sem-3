// Define a structure for a node in the adjacency list
typedef struct node {
    int vertex;
    struct node* next;
}node;

// Define the structure for the graph
typedef struct graph {
    int numVertices;
    node** adjLists;       // Array of adjacency lists
}graph;

typedef struct queue
{   
    int * data;
    int size;
    int front, rear;
}queue;

void initQueue(queue *q, int size);
void enqueue(queue * q, int data);
int dequeue(queue * q);
int isempty(queue * q);
int isfull(queue * q);

void init_graph(graph *g,int v);
void addEdge(graph *g,int s,int d);
node * create_node(int d);
void display_list(graph *g);
void BFS(graph g,int sVertex);
void DFS(graph g,int sVertex);
int isCyclicConnected(graph* g, int start);
int isCyclicDisconnected(graph* g);
void freeGraph(graph* g);
