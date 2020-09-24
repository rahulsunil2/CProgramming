#include<stdio.h>


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

void main(){
	int nVertices, nEdges;
	printf("Vertices : ");
	scanf("%d", &nVertices);
	printf("Edges : ");
	scanf("%d", &nEdges);

}