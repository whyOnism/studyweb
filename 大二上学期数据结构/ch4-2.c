#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
#define STACK_SIZE 10000
 

typedef struct Squeue{
	int data[MAXSIZE];
	int front;
	int rear;
}Squeue;
 
 
typedef struct{
    int *base;
    int *top;
    int size;
}seqStack;

int InitStack(seqStack *s){
    s->base = (int *)malloc(STACK_SIZE* sizeof(seqStack));
    
    s->top = s->base;
    s->size = STACK_SIZE;
    return 1;
}
int Push(seqStack *s,int x){
 
    *s->top = x;
    s->top++;
    return 1;
}
 
int Pop(seqStack *s,int *x){
    if(s->top == s->base)return 0;
    else{
        s->top--;
        *x = *s->top;
        return 1;
    }
}
int GetTop(seqStack *s, int *x){
    if(s->top==s->base)
		return 0;
    else{
        *x=*(s->top-1);
        return 1;
    }
}
void InitQueue(Squeue *Q)
{
	Q->front = Q->rear = 0;
}
int isQueueEmpty(Squeue *qu)
{
	if(qu->front == qu->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int EnQueue(Squeue *qu,int x)
{
	if((qu->rear + 1) % MAXSIZE == qu->front)
	{
		return 0;
	}
	qu->rear = (qu->rear + 1) % MAXSIZE;
	qu->data[qu->rear] = x;
	return 1;
}
int deQueue(Squeue *qu,int *x)
{
	if(qu->front == qu->rear)
	{
		return 0;
	}
	qu->front = (qu->front + 1) % MAXSIZE;
	*x = qu->data[qu->front];
	return 1;
}
int main()
{
	int i , n , x , a;
	scanf("%d",&n);
 
	Squeue q;
	seqStack s;
 
    InitStack(&s);
	InitQueue(&q);
 
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a);
		Push(&s,a);
	}
	
	int stackNumber;
	for(i=0;i<n;i++)
    {
        Pop(&s,&stackNumber); 
        EnQueue(&q,stackNumber);
    }
    while(!isQueueEmpty(&q))
	{
		deQueue(&q,&x);
		printf("%d ",x); 
	}
	
	return 0;
}
