#include <stdio.h>
#include <stdlib.h>
#define Max 100

void findmin(int arr[],int n,int m){
	int i,j,k;
	for (i=0;i<n;i++){
		int minIndex=i;
		int min=arr[i];
		for(j=i+1;j<n;j++){
			if(min>arr[j]){
				min=arr[j];
				minIndex=j;
			}
		}
		if(minIndex!=i){
			arr[minIndex]=arr[i];
			arr[i]=min;
		}
	}
	for(k=0;k<m;k++)
	printf("%d ",arr[k]);
}


int main(){
	int i=0,m;
	int arr[Max];
	while(1){
		scanf("%d",&arr[i]);
		i++;
		if(getchar()=='\n') break;
	}
	scanf("%d",&m);
	findmin(arr,i,m);
	return 0;
}
