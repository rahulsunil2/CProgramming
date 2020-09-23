// Rahul Sunil
// 46
// CS1 S5

#include <stdio.h>
#include <stdlib.h> 

int v, e; 
struct adjListNode { 
    int dest; 
    struct adjListNode* next; 
}; 
 
struct adjList { 
    struct adjListNode *head;  
}; 
  

struct graph { 
    int V; 
    struct adjList* array; 
}; 
   
struct adjListNode* newAdjListNode(int dest) { 
    struct adjListNode* newNode = 
     (struct adjListNode*) malloc(sizeof(struct adjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
};
   
struct graph* createGraph(int V) { 
    struct graph* graph =  
        (struct graph*) malloc(sizeof(struct graph)); 
    graph->V = V; 

    graph->array =  
      (struct adjList*) malloc(V * sizeof(struct adjList)); 

    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 

void addEdge(struct graph* graph, int src, int dest) { 

    struct adjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 

    newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
}

void matrixInit(int matrix[v][v]) { 
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++)
            matrix[i][j] = 0;
    }
}

void adjacencyMatrix(int e1, int e2, int adj[v][v], int ch) {
	adj[e1][e2] = 1;
	if (ch == 2) {
		adj[e2][e1] = 1;
	}
}

void printGraph(struct graph* graph) { 
    for (int i= 0; i < graph->V; ++i) { 
        struct adjListNode* pCrawl = graph->array[i].head; 
        printf("\n Adjacency list of vertex %d\n head ", i); 
        while (pCrawl) { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    }
}

void displayMatrix(int matrix[v][v]) {
	printf("\nAdjacency Matrix \n");
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}


void main() {
	int e1, e2, ch;
	printf("1. Directed graph\n2. Undirected graph\n");
	printf("Choice               : ");
	scanf("%d", &ch);
	printf("Vertices             : ");
	scanf("%d", &v);
	struct graph* graph = createGraph(v); 
	printf("Edges                : ");
	scanf("%d", &e);
	int matrix[v][v];
	matrixInit(matrix);
	for (int i=0; i<e; i++) {
	    printf("Edge vertices (0-%d) : ", (v-1));
		scanf("%d %d", &e1, &e2);
		adjacencyMatrix(e1, e2, matrix, ch);
		addEdge(graph, e1, e2);
	}
	displayMatrix(matrix);
	printGraph(graph); 
}
