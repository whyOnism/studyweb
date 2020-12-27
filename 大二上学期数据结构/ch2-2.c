/*将非空线性链表中数据域值最大的那个链结点移至链表的末尾
q用来指向最大值结点的地址，最开始假定第一个结点为域最大值结点，p用来遍历链表，
r用来在遍历过程中所比较值域链结点的直接前驱结点，s用来记录最大值域节点的直接前驱结点*/
#include <stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *link;
}LNode, *LinkList;

LinkList 

void removeElemToEnd( LinkList *list ){
    LinkList q = *list, p = ( *list )->link, r = *list, s;
    while( p != NULL ){     //寻找最大值结点及其前驱结点
        if(strcmp( p->data, q->data ) > 0){     //如果新的链结点大于之前记录的域最大结点,则更新s, q的值
            s = r;
            q = p;
        }
        r = p;          //如果新的链结点不大于之前记录的域最大结点，则跳到下一个链结点
        p = p->link;
    }
 
    if( q != r ){      //如果最大值结点不是链表的末尾结点
        if( q == *list ){     //如果最大值结点是链表的第一个结点
            *list = ( *list )->link;
        }
        else{                //如果最大值结点不是链表的第一个结点
            s->link = q->link;
        }
 
        r->link = q;   //将最大值结点移动至末尾，并将新的末尾结点的指针域置空
        q->link = NULL;
    }
}
int main(){
	struct LinkList *list,*pre;
    while(getchar()!=EOF){
    	scanf("%d",&pre->data);	
    	pre->link=(LinkList)malloc(sizeof(LinkList));//申请下一个节点
        pre=pre->link;
        
	}
	return 0;
}
