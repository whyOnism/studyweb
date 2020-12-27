#include<stdio.h>
#include<stdlib.h>
 
#define INFINITY 99999
#define MAX 501
 

typedef struct GNode{
    int Nv,Ne;
    int G[MAX][MAX];
    int G1[MAX][MAX];
}PtrToGNode,*MGraph;
 
typedef struct ENode{
    int V1,V2;
    int Weight;
    int Data;
}PtrToENode,*Edge;
 
MGraph CreateGraph(int VertexNum){
    MGraph graph;
    graph = (MGraph)malloc(sizeof(struct GNode));
    graph->Nv = VertexNum;
    graph->Ne = 0;
    int V, W;
    for(V=0; V<graph->Nv; V++)
        for(W=0; W<graph->Nv; W++)
            graph->G[V][W] = INFINITY;
    return graph;
}
 
void InsertEdge(MGraph graph, Edge E){
    int V = E->V1;
    int W = E->V2;
    graph->G[V][W] = E->Weight;
    graph->G[W][V] = E->Weight;
    graph->G1[V][W] = E->Data;
    graph->G1[W][V] = E->Data;
}
 
int D[MAX][MAX];
int Cost[MAX][MAX];
int Path[MAX][MAX];
void Floyd(MGraph graph){
    int i, j, k;
    for(i=0; i<graph->Nv; i++){
        for(j=0; j<graph->Nv; j++){
            D[i][j] = graph->G[i][j];
            Cost[i][j] = graph->G1[i][j];  
            Path[i][j] = -1;
        }
    }
    for(k=0; k<graph->Nv; k++){
        for(i=0; i<graph->Nv; i++){
            for(j=0; j<graph->Nv; j++){
                if(D[i][k]+D[k][j]<D[i][j]||(D[i][k]+D[k][j]==D[i][j]&&
				Cost[i][k]+Cost[k][j]<Cost[i][j])){
                    D[i][j] = D[i][k]+D[k][j];
                    Path[i][j] = k;
                    Cost[i][j] = Cost[i][k]+Cost[k][j];
                }
            }
        }
    }
}
int a[MAX];
int num = 1;
void ThePath(int V, int W){
    int S = Path[V][W];
    if(S==-1){
        return;
    }
    ThePath(V, S);
    a[num++] = S;
    ThePath(S, W);
}
 
int main(){
    int N, M;
    int V, W;
    scanf("%d%d%d%d",&N, &M, &V, &W);
    MGraph graph = CreateGraph(N);
    graph->Nv = N;
    graph->Ne = M;
    int i;
    Edge E;
    for(i=0; i<M; i++){
        E = (Edge)malloc(sizeof(struct ENode));
        scanf("%d%d%d%d",&E->V1,&E->V2,&E->Weight,&E->Data);
        InsertEdge(graph, E);
    }
    Floyd(graph);
    printf("%d %d",D[V][W],Cost[V][W]);
    return 0;
}


