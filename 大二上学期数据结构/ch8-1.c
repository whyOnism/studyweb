#include <stdio.h>
#define MaxNum 100

void SelectSort(int arr[],int m){
	int i,j,k;
	for (i=0;i<m;i++){
		int minIndex=i;
		int min=arr[i];
		for(j=i+1;j<m;j++){
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
	int arr[MaxNum];
	int m=0;
	while(1){	
		scanf("%d",&arr[m]);
		m++;
		if(getchar()==EOF)
		break;
	}
	SelectSort(arr,m);
	return 0;
}
