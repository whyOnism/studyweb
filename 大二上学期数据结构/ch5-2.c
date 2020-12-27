#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
        int data;
        struct Node *leftchild,*rightchild;
}BNode,*BTree;

 
int len;
BTree heap[20];
void swap(BTree *a,BTree *b)
{
     BTree tmp=*a;
     *a=*b;
     *b=tmp;
}
void push_heap(BTree *heap,BTree s)
{
     heap[++len]=s;
     int t=len;
     while (t>1)
     {
           if (heap[t>>1]->data>heap[t]->data)
           {
              swap(&heap[t>>1],&heap[t]);
           }
           else return;
     }
}
BTree pop_heap(BTree *heap)
{
     BTree re=heap[1],x;
     heap[1]=heap[len--];
     int m=len>>1,t=1,k;
     while (t<=m)
     {
        k=t;
        if (heap[t<<1]->data<heap[t]->data)
           k=t<<1;
        if ((t<<1)+1<=len)
           if(heap[k]->data>heap[(t<<1)+1]->data)
              k=(t<<1)+1;
     
        if (k!=t)
        {
           swap(&heap[k],&heap[t]);
           t=k;
        }
        else return re;
     }
     return re;
}
void heap_adjust(BTree *heap,int pos,int end)
{
     int i;
     BTree t=heap[pos];
     for (i=2*pos;i<=end;i<<=1)
     {
         if (i<end && heap[i]->data<heap[i+1]->data)
            ++i;
         if (heap[pos]->data>heap[i]->data) break;
         heap[pos]=heap[i];
         pos=i;
     }
     heap[pos]=t;
}
void sort_heap(BTree *heap)
{
     int i;
     BTree t;
     for (i=len/2;i>0;i--)
         heap_adjust(heap,i,len);
     for (i=len;i>1;i--)
     {
         swap(&heap[1],&heap[i]);
         heap_adjust(heap,1,i-1);
     }
}
int main()
{
    BTree root,lchild,rchild;
    scanf("%d",&len);
    int i;
    int ans=0;
    for (i=1;i<=len;++i)
    {
        heap[i]=(BTree)malloc(sizeof(BNode));
        scanf("%d",&heap[i]->data);
    }
    sort_heap(heap);                         
    while (len>1)
    {
         lchild=pop_heap(heap); 
         rchild=pop_heap(heap);
         root=(BTree)malloc(sizeof(BNode));      
         root->data=lchild->data+rchild->data;
         ans+=root->data;
         root->leftchild=lchild;
         root->rightchild=rchild;
         push_heap(heap,root);
    }
    root=pop_heap(heap);                          
    printf("%d\n",ans);                   
}






