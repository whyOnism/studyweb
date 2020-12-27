#include<stdio.h>
int rb(int nums[],int n,int target){
	if(n==0){
		return -1;//长度为0返回-1 
	}
	int left = 0;
	int right = n ; 
	while(left<right){
		int mid = ( left + right ) / 2 ;
		if(nums[mid]<target){
			left = mid + 1 ;
		}else if( nums[mid] > target){
			right = mid ; 
		}else{
			right = mid ;
		}
	}
	return left ;
}
int main(){
	
	int nums [50];

	int i = 0;
	int n ; 
	char ch; 
	do{
		scanf("%d",&nums[i]);
		i++;		
	}while((ch=getchar())!='\n');
	n = i;
	int target = 0;
	scanf("%d",&target);
	int result ;
	result = rb(nums,n,target); 
	printf("%d",result-1);

	return 0;
}


