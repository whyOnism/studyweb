/*���ǿ�����������������ֵ�����Ǹ���������������ĩβ
q����ָ�����ֵ���ĵ�ַ���ʼ�ٶ���һ�����Ϊ�����ֵ��㣬p������������
r�����ڱ������������Ƚ�ֵ��������ֱ��ǰ����㣬s������¼���ֵ��ڵ��ֱ��ǰ�����*/
#include <stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *link;
}LNode, *LinkList;

LinkList 

void removeElemToEnd( LinkList *list ){
    LinkList q = *list, p = ( *list )->link, r = *list, s;
    while( p != NULL ){     //Ѱ�����ֵ��㼰��ǰ�����
        if(strcmp( p->data, q->data ) > 0){     //����µ���������֮ǰ��¼���������,�����s, q��ֵ
            s = r;
            q = p;
        }
        r = p;          //����µ�����㲻����֮ǰ��¼��������㣬��������һ�������
        p = p->link;
    }
 
    if( q != r ){      //������ֵ��㲻�������ĩβ���
        if( q == *list ){     //������ֵ���������ĵ�һ�����
            *list = ( *list )->link;
        }
        else{                //������ֵ��㲻������ĵ�һ�����
            s->link = q->link;
        }
 
        r->link = q;   //�����ֵ����ƶ���ĩβ�������µ�ĩβ����ָ�����ÿ�
        q->link = NULL;
    }
}
int main(){
	struct LinkList *list,*pre;
    while(getchar()!=EOF){
    	scanf("%d",&pre->data);	
    	pre->link=(LinkList)malloc(sizeof(LinkList));//������һ���ڵ�
        pre=pre->link;
        
	}
	return 0;
}
