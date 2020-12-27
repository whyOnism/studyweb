#include<stdio.h>
int main(){
	int nums [50];
	int i = 0;
	int n ; 
	char ch; 
	int max = 0;
	do{
		scanf("%d",&nums[i]);
		if(max<nums[i]){
			max = nums[i];
		}
		i++;		
	}while((ch=getchar())!=EOF);
	n = i;
	int index[10];
	for( i = 0 ;i<= 10 ;i++){
		index[i]=0;
	}
	for(i=0; i < n;i++){
		index[nums[i]]++;
	}
	int flag = -1;
	for(i=0;i<n;i++){
		if(index[nums[i]]>n/2) {
			printf("%d",nums[i]);
			flag=0; 
			break;
		}
	}
	if(flag==-1){
		printf("-1");
	}
	return 0;
}



