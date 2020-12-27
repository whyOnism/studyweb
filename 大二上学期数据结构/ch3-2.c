#include<stdio.h>
#include<string.h>
#define  MAX 100
typedef struct
{
    int Data[MAX];   // 存储元素的数组
    int topIdx;       //栈顶指针
} SeqStack;



//return 0 为false,1为true(下同)
// 将元素推入栈中
int Push(SeqStack* L, int e)
{   // 栈已满
    if(L->topIdx==MAX -1)
    {
        return 0;
    }
    // 加入栈中
    L->Data[L->topIdx++] = e;
    // 返回自身
    return 1;
}
// 移除栈顶元素
int Pop(SeqStack* L,int *val)
{   // 栈空
    if(L->topIdx == 0)
    {
        //返回失败
        return 0;
    }

    *val = L->Data[--(L->topIdx)];
    return 1;
}
//判断栈s是否为空
int isEmpty(SeqStack s)
{
    // 如果下标在0，说明栈中无元素
    if(s.topIdx == 0)
    {
        return 1;
    }
    return 0;
}
// 判断栈是否已栈.
int isFull(SeqStack s)
{
    // 已满返回true(1)
    if(s.topIdx == MAX -1)//之前的定义数组的最大值的下标
    {
        return 1;
    }
    return 0;
}
// 初始化
SeqStack* init() {
    SeqStack* s =(SeqStack*) malloc(sizeof(SeqStack));
    if(s!=NULL) {
    	s->topIdx=0;
        return s;
    } else {
        printf("申请失败");
        return NULL;
    }
}

int toD(char ch);
int isD(char ch);

int main() {
    SeqStack *s= init();
    char str[100];
    gets(str);
    int i=0,t=0;
    int a1=0,a2=0;
    int a3=0;
    for(i=0; i<strlen(str); i++) {
        if(str[i]!=' ') {
            if(isD(str[i])) {
                  int b=toD(str[i]);//给b初值就是第一位
                //处理输入的数字不是一位数的情况
                while(str[i+1]!=' '){
                  b=b*10;
                  t=toD(str[++i]);
                  b=b+t;
                }
                Push(s,b);
            }
            //默认除了数字和空格外其他都是合法的符号
            else {
                //弹出两个数字
                Pop(s,&a1);
                Pop(s,&a2);
                if(str[i]=='+') {
                    a3= a2+a1;
                    Push(s,a3);
                } else if(str[i]=='-') {
                    a3= a2-a1;
                    Push(s,a3);
                } else if(str[i]=='/') {
                    a3= a2/a1;
                    Push(s,a3);
                } else if(str[i]=='*') {
                    a3= a2*a1;
                    Push(s,a3);
                }
            }
        }

    }

    printf("%d",a3);
    return 0;
}
//如果是数字
int isD(char ch) {
    if(ch>='0'&&ch<='9') {
        return 1;
    } else {
        return 0;
    }
}

//转化成数字
int toD(char ch) {
    return  ch-'0';
}

