#include <stdio.h>
#include <stdlib.h>
#define max 100
typedef struct sta
{
    char data[max];
    int top;
} stack;
stack* init()
{
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    return s;
}
int empty(stack *s)
{
    if(s->top==-1)
        return 1;
    else return 0;
}
int push(stack* s,char x)
{
    if(s->top==max-1) return -1;
    else
    {
        s->top++;
        s->data[s->top]=x;
        return 1;
    }
}
int pop(stack* s,char *x)
{
    if(empty(s)) return 0;
    else
    {
        *x=s->data[s->top];
        s->top--;
        return 1;
    }
}

int main(){ 
    char x;
	int flag=0,flag1=0;
	int res=0,ms=0,ns=0;
    stack *s=init();
    while((x=getchar())!='@')
    {
        if(x=='('){
            flag=push(s,x);
            ms++;
    	}
        if(x==')'){
            flag1=pop(s,&x);
            ns++;
        }
	}  
    if((ns>=1) && (ms==ns))
        printf("%d",ns);
    else if(ms!=ns)
		printf("no");
	else
		printf("no");
    return 0;
}
