#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "queue.h"
// #include "stack.h"

// Function to initialize a graph with a specified number of vertices
void init_graph(graph *g,int v){
	g->numVertices = v;
	g->adjLists = (node**)malloc(v * sizeof(node*));
	for (int i = 0; i < v; i++) {
        	g->adjLists[i] = NULL;
    }
    return;
}

// Function to create a new node
node * create_node(int d){
	node* nn = (node*)malloc(sizeof(node));
    	nn->vertex = d;
    	nn->next = NULL;
    	return nn;
}
// Function to add an undirected edge to the graph
void addEdge(graph *g,int s,int d){
    // Add edge from src to dest
    node* nn = create_node(d);
    nn->next = g->adjLists[s];
    g->adjLists[s] = nn;

    // Add edge from dest to src (since the graph is undirected)
    nn = create_node(s);
    nn->next = g->adjLists[d];
    g->adjLists[d] = nn;
}


void display_list(graph *g){
	for(int i=0; i < g->numVertices; i++){
        printf("Adjacency list for vertex %d :", i);
        node *p = g->adjLists[i];
        while(p){
            printf("%d ", p->vertex);
            p=p->next;
        }
        printf("\n");
    }
}




void BFS(graph g, int sVertex){
	int k,i;
    	queue q;
    	initQueue(&q, g.numVertices);
    	int *visited=(int *)calloc(g.numVertices,sizeof(int));
    visited[sVertex]=1;
    enqueue(&q, sVertex);
    printf("%d ", sVertex);
    while(!isempty(&q)){
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

// void DFS(graph g,int sVertex){
// 	stack s;
//     	int k, i;
//     	init_stack(&s, g.numVertices);
//     	int *visited=(int *)calloc(g.numVertices, sizeof(int));
//     visited[sVertex]=1;
//     push(&s, sVertex);
//     printf("%d ", sVertex);
//     while(!isempty_s(s)){
//         k=pop(&s);
//         if(visited[k]==0){
//             visited[k]=1;
//             printf("%d ", k);
//         }
//         node *p = g.adjLists[k];
//         while(p){
//             i=p->vertex;
//             if(visited[i]==0){
//                 push(&s, i);
//             }
//             p=p->next;
//         }
//     }
// }

// int isCyclicConnected(graph* g, int start){
// 	queue q;
//     initQueue(&q, g->numVertices);
//     enqueue(&q, start);
//     int *visited=(int *)calloc(g->numVertices, sizeof(int));
//     visited[start]=1;
//     while (!isempty(&q)) {
//        	int current = dequeue(&q);  
//         if(visited[current] != visited[start]){           		           		       
//             return 1;  // Cycle detected
//         }

//         visited[current] = 1;

//         node* p = g->adjLists[current];
//         while (p) {
//             if (!visited[p->vertex]) {
//                 enqueue(&q, p->vertex);
//             }
//             p = p->next;
//         }
//     }
//     return 0;
// }


int isCyclicConnected(graph* g, int start) {
    queue q;
    initQueue(&q, g->numVertices);
    enqueue(&q, start);

    int visited[g->numVertices];
    for(int i = 0; i < g->numVertices; i++){
        visited[i] = 0;
    }
    visited[start] = 1;

    int parent[g->numVertices]; // Array to track parent nodes
    for (int i = 0; i < g->numVertices; i++) {
        parent[i] = -1; // Initialize parent for all vertices as -1
    }

    while (!isempty(&q)) {
        int current = dequeue(&q);

        node* p = g->adjLists[current];
        while (p) {
            int i = p -> vertex;
            if (!visited[i]) {
                visited[i] = 1;
                parent[i] = current; // Set parent
                enqueue(&q, i);
            } else if (parent[current] != i) {
                // If the adjacent node is visited and is not the parent, cycle exists
                return 1;
            }
            p = p->next;
        }
    }
    return 0;  // No cycle detected
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


void initQueue(queue *q, int size) {
    q->data = (int *)malloc(sizeof(int) * size);
    if (q->data == NULL) {
        printf("Memory allocation failed for queue.\n");
        exit(1);
    }
    q->size = size;
    q->front = -1;
    q->rear = -1;
}

int isempty(queue *q) {
    return q->rear == -1;
}

int isfull(queue *q) {
    return q->rear == q->size - 1;
}

void enqueue(queue *q, int data) {
    if (isfull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", data);
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->data[q->rear] = data;
}

int dequeue(queue *q) {
    if (isempty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int data = q->data[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return data;
}






/*void freeGraph(graph* g){
	for (int i = 0; i < g->numVertices; i++) {
        	node* p = g->adjLists[i];
        	while (p) {
            		node* next = p->next;
            		free(p);
            		p = next;
        	}
    }
    free(g->adjLists);
    free(&g);

}*/

