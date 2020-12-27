#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
	int arcs[100][100];
	int vertex[100];
}G;

void creatGraph(G *g,int n){
	int i = 0 , j = 0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&g->arcs[i][j]);
		}
	}
}

void initVisited(int visited[],int n){
	int i = 0;
	for(i=0;i<n;i++){
		visited[i]=0;
	}
}

void DFS(G* g,int i,int n,int visited[]){
	visited[i]=1;
	int j=0;
	for(j=0;j<n;j++){
		if(!visited[j]&&g->arcs[i][j]==1){
			DFS(g,j,n,visited);
		}
	} 
}

void LinkG(G* g,int n,int visited[]){
	int i=0,flag=0;
	for(i=0;i<n;i++){
		if(!visited[i]){
			flag++;
			DFS(g,i,n,visited); 
		}
	}
	printf("%d",flag);
}
int main(){
	G* g = (G*)malloc(sizeof(G));	
	int visited[100];
	int n;
	scanf("%d",&n);
	creatGraph(g,n);
	initVisited(visited,n);
	LinkG(g,n,visited);
	return 0;
} 


