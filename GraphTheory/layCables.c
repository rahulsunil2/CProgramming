#include<stdio.h>
 
#define MAX 30

// GraphEdgeWeights -> Array storing the weights of edges in the graph.
int GraphEdgeWeights[MAX][MAX];

// nVertices -> No: of vertices in the graph.
int nVertices;
 
// Edge -> Structure for an edge with its source vertex, destination vertex and its weight.
typedef struct Edge{
    int src, dest, weight;
} Edge;

// EdgeList -> Structure for storing an array of Edge along with its size.
typedef struct EdgeList{
    Edge data[MAX];
    int size;
} EdgeList;

EdgeList edgeList;
EdgeList spanList;

// Function name : SortEdges
// Input         : void
// Output        : void
// Logic         : For sorting the edges based on their weights.
void SortEdges(){
    int i, j;
    Edge tempEdge;
    
    for(i=1; i<edgeList.size; i++)
        for(j=0; j<edgeList.size-1; j++)
            if(edgeList.data[j].weight > edgeList.data[j+1].weight){
                tempEdge            = edgeList.data[j];
                edgeList.data[j]    = edgeList.data[j+1];
                edgeList.data[j+1]  = tempEdge;
            }
}

// Function name : FindParent
// Input         : parent array, vertexNo
// Output        : parent
// Logic         : For finding the parent of a node in the spanning tree.
int FindParent(int parent[], int vertexNo){
    return(parent[vertexNo]);
}

// Function name : Union
// Input         : parent array, source node, destination node
// Output        : void
// Logic         : For adding the both nodes to the same parent.
void Union(int parent[], int srcNode, int destNode){
    int i;
    for(i=0; i<nVertices; i++)
        if(parent[i] == destNode)
            parent[i] = srcNode;
}

// Function name : KruskalPathFinder
// Input         : void
// Output        : void
// Logic         : For generating a minimum spanning tree.
void KruskalPathFinder(){

    // Initialising the variables.
    int parent[MAX], i, j, srcRoot, destRoot;
    
    // Initialising the edgeList.
    edgeList.size = 0;
    for(i=1; i<nVertices; i++){
        for(j=0; j<i; j++){
            if(GraphEdgeWeights[i][j] != 0){
                edgeList.data[edgeList.size].src     = i;
                edgeList.data[edgeList.size].dest    = j;
                edgeList.data[edgeList.size].weight  = GraphEdgeWeights[i][j];
                edgeList.size++;
            }
        }
    }

    // Sorting the edges based on their weights.
    SortEdges();
    
    // Assigning parents to every node of the tree.
    for(i=0; i<nVertices; i++)
        parent[i] = i;
    
    // Creating the Minimum Spanning Tree.
    spanList.size = 0;
    for(i=0;i<edgeList.size;i++){
        // Find Operation
        srcRoot = FindParent(parent, edgeList.data[i].src);
        destRoot = FindParent(parent, edgeList.data[i].dest);
        
        if(srcRoot != destRoot){
            spanList.data[spanList.size] = edgeList.data[i];
            spanList.size++;
            // Union Operation
            Union(parent, srcRoot, destRoot);
        }
    }
}

// Function name : PrintResult
// Input         : void
// Output        : void
// Logic         : For printing the result that is the cost of traversing the spanning tree.
void PrintResult(){
    int i,cost=0;
    
    for(i=0; i<spanList.size; i++){
        printf("\n%d->%d:%d", 
            spanList.data[i].src, 
            spanList.data[i].dest, 
            spanList.data[i].weight);
        cost = cost + spanList.data[i].weight;
    }
    printf("\n=====================================\n")
    printf("Cost of the laying the cable = %d", cost);
}

// Function name : main
// Input         : void
// Output        : void
// Logic         : The driver function of the program.
void main(){
    int i, j, total_cost, weight;
    
    printf("\nNumber of cities : ");
    scanf("%d",&nVertices);
    
    for(i=0; i<nVertices; i++){
        for(j=0; j<nVertices; j++){
            if(i!=j){
                if(i<j){
                    printf("Cost for laying the cable from city %d to city %d : ", i, j);
                    scanf("%d", &weight);
                    GraphEdgeWeights[i][j] = weight;
                }
                else{
                    GraphEdgeWeights[i][j] = GraphEdgeWeights[j][i];
                }
            }
            else{
                GraphEdgeWeights[i][j] = 0;
            }
        }

    }
            
    KruskalPathFinder();
    PrintResult();
}
 
