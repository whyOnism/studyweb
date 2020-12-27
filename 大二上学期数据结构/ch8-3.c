#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MaxNum 100
#define Cutoff 3
int indexno=0;//计比较次数 
/*1.选择排序函数*/ 
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
			indexno++;
		}
		if(minIndex!=i){
			arr[minIndex]=arr[i];
			arr[i]=min;
		}
	}
	for(k=0;k<m;k++)
		printf("%d ",arr[k]);
	printf("\n%d ",indexno);
}
/*2.冒泡函数*/ 
void BubbleSort(int arr[],int m){
	int i,j,k;
	for(i=0; i<m-1; i++)
    {
        int isSorted = 1;
        for(j=0; j<m-1-i; j++)
        {
        	indexno++;
            if(arr[j] > arr[j+1])
            {
                isSorted = 0;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(isSorted) break;
    }
    for(k=0;k<m;k++)
		printf("%d ",arr[k]);
	printf("\n%d ",indexno);
}
/*3.堆排序函数*/ 
void HeapAdjust(int a[],int s,int m)
{
    int rc,j;
    rc=a[s];
    for(j=2*s;j<=m;j=j*2)
    {
    	indexno++;
        if(j<m&&a[j]<a[j+1])j++;
        if(rc>a[j]) break;
        a[s]=a[j];s=j;
    }
    a[s]=rc;
}
void HeapSort(int a[],int n)
{
    int temp,i,k;
    for(i=n/2;i>0;i--)
    {
        HeapAdjust(a,i,n);
    }
    for(i=n;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        HeapAdjust(a,1,i-1);
    }
    for(k=1;k<=n;k++)	
			printf("%d ",a[k]);
	printf("\n%d ",indexno);
}
/*4.二路归并排序函数*/
void Merge(int arr[],int temparr[],int Lpos,int Rpos,int RightEnd){
	int i,LeftEnd,NumElements,TmpPos;
	LeftEnd=Rpos-1;
	TmpPos=Lpos;
	NumElements=RightEnd-Lpos+1;
	while(Lpos<=LeftEnd&&Rpos<=RightEnd){
		indexno++;
		if(arr[Lpos]<=arr[Rpos])
			temparr[TmpPos++]=arr[Lpos++];
		else
			temparr[TmpPos++]=arr[Rpos++];
			}
	while(Lpos<=LeftEnd)
		temparr[TmpPos++]=arr[Lpos++];
	while(Rpos<=RightEnd)
		temparr[TmpPos++]=arr[Rpos++];
	for(i=0;i<NumElements;i++,RightEnd--)
		arr[RightEnd]=temparr[RightEnd];
}

void MSort(int arr[],int temparr[],int Left,int Right){
	int Center;
	if(Left<Right){
		Center=(Left+Right)/2;
		MSort(arr,temparr,Left,Center);
		MSort(arr,temparr,Center+1,Right);
		Merge(arr,temparr,Left,Center+1,Right);
		}
}

void MergeSort(int arr[],int n){
	int *temparr;
	int k;
	temparr = (int*)malloc(sizeof(n*sizeof(int)));
	if(temparr!=NULL){
		MSort(arr,temparr,0,n-1);
	//	free(temparr);/*free会死循环？*/
	}
	else
		printf("No space for tmp array!!!");
	for(k=0;k<n;k++)
		printf("%d ",arr[k]);
	printf("\n%d ",indexno);
		
}

/*5.快速排序函数*/
void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Median3(int arr[],int Left,int Right){
	int Center;
	Center=(Left+Right)/2;
	if(arr[Left]>arr[Center])
		Swap(&arr[Left],&arr[Center]);
	if(arr[Left]>arr[Right])
		Swap(&arr[Left],&arr[Right]);
	if(arr[Center]>arr[Right])
		Swap(&arr[Center],&arr[Right]);
	Swap(&arr[Center],&arr[Right-1]);
	return arr[Right-1];
}

void InsertionSort(int arr[],int len){
    int temp,i,j;	
    for(i=0;i<len;i++){
        for(j=i;j>0;j--){
            if(arr[j]<arr[j-1]){    
             temp=arr[j];
             arr[j]=arr[j-1];
             arr[j-1]=temp;
           }
        }
    }    
  return;
}

void QSort(int arr[],int Left,int Right){
	int i,j;
	int Pivot;
	if(Left+Cutoff<=Right){
		Pivot=Median3(arr,Left,Right);
		i=Left;j=Right-1;
		for(;;){
			while(arr[++i]<Pivot){}
			while(arr[--j]>Pivot){}
			if(i<j){
				Swap(&arr[i],&arr[j]);
				}
			else{
				break;}			
			}
			Swap(&arr[i],&arr[Right-1]);
			QSort(arr,Left,i-1);
			QSort(arr,i+1,Right);
	}
	else
		InsertionSort(arr+Left,Right-Left+1);
}

void QuickSort(int arr[],int n){
	int k;
	QSort(arr,0,n-1);
	for(k=0;k<n;k++)
		printf("%d ",arr[k]);
	printf("\n%d ",indexno);
}

int main(){
	int arr[MaxNum];
	int m=0,p,i;
	scanf("%d %d",&m,&p);
	if(p==3){
		for(i=1;i<=m;i++)
			scanf("%d",&arr[i]);
		}
	else{
		for(i=0;i<m;i++)
			scanf("%d",&arr[i]);
	}
	switch(p){
		case 1:SelectSort(arr,m);break;
		case 2:BubbleSort(arr,m);break;
		case 3:HeapSort(arr,m);break;
		case 4:MergeSort(arr,m);break;
		case 5:QuickSort(arr,m);break;
	}
	return 0;
}
