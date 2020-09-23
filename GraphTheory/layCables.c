#include<stdio.h>
 
#define MAX 30
 
typedef struct Edge{
    int src, dest, weight;
}Edge;
 
typedef struct EdgeList{
    Edge data[MAX];
    int n;
}EdgeList;
 
EdgeList edgeList;
 
int Graph[MAX][MAX], n;
EdgeList spanList;

void SortEdges(){
    int i, j;
    Edge tempEdge;
    
    for(i=1; i<edgeList.n; i++)
        for(j=0; j<edgeList.n-1; j++)
            if(edgeList.data[j].weight > edgeList.data[j+1].weight){
                tempEdge            = edgeList.data[j];
                edgeList.data[j]    = edgeList.data[j+1];
                edgeList.data[j+1]  = tempEdge;
            }
}

int FindParent(int parent[], int vertexno){
    return(parent[vertexno]);
}
 
void union1(int parent[], int c1, int c2){
    int i;
    
    for(i=0; i<n; i++)
        if(parent[i]==c2)
            parent[i] = c1;
}
 
void kruskal(){
    int parent[MAX], i, j, cno1, cno2;
    edgeList.n = 0;
 
    for(i=1; i<n; i++){
        for(j=0; j<i; j++){
            if(Graph[i][j] != 0){
                edgeList.data[edgeList.n].src = i;
                edgeList.data[edgeList.n].dest = j;
                edgeList.data[edgeList.n].weight = Graph[i][j];
                edgeList.n++;
            }
        }
    }
 
    SortEdges();
    
    for(i=0;i<n;i++)
        parent[i] = i;
    
    spanList.n = 0;
    
    for(i=0;i<edgeList.n;i++){
        cno1 = FindParent(parent, edgeList.data[i].src);
        cno2 = FindParent(parent, edgeList.data[i].dest);
        
        if(cno1!=cno2){
            spanList.data[spanList.n] = edgeList.data[i];
            spanList.n = spanList.n+1;
            union1(parent, cno1, cno2);
        }
    }
}
 
void print(){
    int i,cost=0;
    
    for(i=0;i<spanList.n;i++){
        printf("\n%d->%d:%d", spanList.data[i].src, spanList.data[i].dest, spanList.data[i].weight);
        cost = cost + spanList.data[i].weight;
    }
 
    printf("\n\nCost of the spanning tree = %d", cost);
}
 
void main(){
    int i, j, total_cost,weight;
    
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix :\n");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                if(i<j){
                    printf("Enter the weight for Edge %d %d : ", i, j);
                    scanf("%d", &weight);
                    Graph[i][j] = weight;
                }
                else{
                    Graph[i][j] = Graph[j][i];
                }
            }
            else{
                Graph[i][j] = 0;
            }
        }

    }
            
    kruskal();
    print();
}
 
