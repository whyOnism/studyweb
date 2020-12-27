#include<stdio.h>
#include<stdlib.h>
#define  MAX 100
typedef struct
{
    int Data[MAX];
    int topIdx;
} SeqStack;
int Push(SeqStack* L, int e)
{
    if(L->topIdx==MAX -1)
    {
        return 0;
    }

    L->Data[(L->topIdx)++] = e;

    return 1;
}

int Pop(SeqStack* L,int *val)
{
    if(L->topIdx == 0)
    {
        return 0;
    }

    *val = L->Data[--(L->topIdx)];
    return 1;
}

int isEmpty(SeqStack s)
{
    if(s.topIdx == 0)
    {
        return 1;
    }
    return 0;
}

int getTop(SeqStack s){
	if(!isEmpty(s)){
		  return s.Data[s.topIdx-1];
	}
     return 0; 
}

int isFull(SeqStack s)
{
    if(s.topIdx == MAX -1)
    {
        return 1;
    }
    return 0;
}

SeqStack* init() {
    SeqStack* s =(SeqStack*) malloc(sizeof(SeqStack));
    if(s!=NULL) {
    	s->topIdx=0;
        return s;
    } else {
        printf("…Í«Î ß∞‹");
        return NULL;
    }
}

int main()
{
    SeqStack* s=init();
    int i=0,j=0,n;
    scanf("%d",&n);
    int a[n];
	int b[n];
    for(i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
       scanf("%d",&b[i]);
    }
 	int temp=0;
    for(i=0;i<n;i++){
       Push(s,a[i]);
	   while(!isEmpty(*s) && getTop(*s)==b[j]){
 			Pop(s,&temp);
        	j++;
       }
    }
    if(isEmpty(*s)){
    	printf("%d",n);
	}else{
		printf("0");
	}
    return 0;
}


