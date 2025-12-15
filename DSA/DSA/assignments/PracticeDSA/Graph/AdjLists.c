#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dest;
    struct Node *next;
}Node;

typedef struct Graph{
    int numVertices;
    Node **adjList;
}Graph;

Node *createNode(int dest){
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode -> dest = dest;
    newnode -> next = NULL;
    return newnode;
}

void initGraph(Graph *graph, int vertices){
    graph -> numVertices = vertices;
    graph -> adjList = (Node **)malloc(sizeof(Node *) * vertices);
    for(int i = 0; i < vertices; i++){
        graph -> adjList[i] = NULL;
    }
}

void addEdge(Graph *graph, int src, int dest){
    Node *newnode = createNode(dest);
    newnode -> next = graph -> adjList[dest];
    graph -> adjList[dest] = newnode;

    newnode = createNode(src);
    newnode -> next = graph -> adjList[src];
    graph -> adjList[src] = newnode;
}

void displayGraph(Graph *graph){
    for(int i = 0; i < graph -> numVertices; i++){
        Node *temp = graph -> adjList[i];
        printf("Vertex %d:", i);
        while(temp){
            printf(" -> %d", temp -> dest);
            temp = temp -> next;
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph){
    for(int i = 0; i < graph -> numVertices; i++){
        Node *temp = graph -> adjList[i];
        while(temp){
            Node *next = temp -> next;
            free(temp);
            temp = next;
        }
    }
    free(graph -> adjList);
}

void BFS(graph g, int sVertex){
	int k,i;
    queue q;
    init(&q, g.numVertices);
    int *visited=(int *)calloc(g.numVertices, sizeof(int));
    visited[sVertex]=1;
    enqueue(&q, sVertex);
    printf("%d ", sVertex);
    while(!isempty(q)){
        k=dequeue(&q);
        node *p = g.adjLists[k];
        while(p){
            i=p->vertex;
            if(visited[i]==0){
                printf("%d ", i);
                enqueue(&q, i);
                visited[i]=1;
            }
            p=p->next;
        }
    }
}

void DFS(graph g,int sVertex){
	stack s;
    	int k, i;
    	init_stack(&s, g.numVertices);
    	int *visited=(int *)calloc(g.numVertices, sizeof(int));
    visited[sVertex]=1;
    push(&s, sVertex);
    printf("%d ", sVertex);
    while(!isempty_s(s)){
        k=pop(&s);
        if(visited[k]==0){
            visited[k]=1;
            printf("%d ", k);
        }
        node *p = g.adjLists[k];
        while(p){
            i=p->vertex;
            if(visited[i]==0){
                push(&s, i);
            }
            p=p->next;
        }
    }
}

int isCyclicConnected(graph* g, int start){
	queue q;
    	init(&q, g->numVertices);
    	enqueue(&q, start);
    	int *visited=(int *)calloc(g->numVertices, sizeof(int));
    	visited[start]=1;
    	while (!isempty(q)) {
        	int current = dequeue(&q);   if(visited[current]){           		           		       return 1;  // Cycle detected
        }

        visited[current] = 1;

        node* p = g->adjLists[current];
        while (p) {
            if (!visited[p->vertex]) {
                enqueue(&q, p->vertex);
            }
            p = p->next;
        }
    }
    return 0;

}


int isCyclicDisconnected(graph* g){
    int *visited=(int *)calloc(g->numVertices, sizeof(int));
    	
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i] && isCyclicConnected(g, i)){
            return 1;
        }
    }
    return 0;
}

int main() {
    int vertices = 4;

    // Initialize graph structure
    Graph g;
    initGraph(&g, vertices);

    // Add edges
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);

    // Display the graph
    displayGraph(&g);

    BFS(g, 0);
    DFS(g, 0);
    if (isCyclicDisconnected(&g)) {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    // Free the allocated memory
    freeGraph(&g);

    return 0;
}