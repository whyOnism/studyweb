#include <stdio.h>
#define N 1000
int main(){
	int a[N],b[N];
	int i,count=1,j=0,k,m,l,n;
	char ch;	
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
		ch=getchar();
		if(ch=='\n' ||ch==EOF){
			break;
		}
	count++;	
	}//¶ÁÈ¡
	for(j=0;j<=i;j++){
		if(a[j]%2==1)
		n++;
	}
	for(l=k=j=0;j<=i;j++){
		if(a[j]%2==1){
			b[k]=a[j];
			k++;
		}
		else {b[n+l]=a[j];
			  l++;
		}
	}
	for(i=0;i<count;i++){
		if(i==count-1)
		printf("%d",b[i]);
		else
		printf("%d,",b[i]);
	}
	return 0;
} 
