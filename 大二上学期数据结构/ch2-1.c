#include <stdio.h>
#include <stdlib.h>

struct creatLink{
	int id;
	int score;
	struct creatLink *next;	
};

int main(){
	int i;
	struct creatLink *head,*pre;
	
	head=(struct creatLink*)malloc(sizeof(struct creatLink));//创建头结点
    pre=(struct creatLink*)malloc(sizeof(struct creatLink));//申请第一个结点
    head->next=pre;
    
    for(i=0;i<3;i++){
    	scanf("%d,%d",&pre->id,&pre->score);	
    	pre->next=(struct creatLink*)malloc(sizeof(struct creatLink));//申请下一个节点
        pre=pre->next;
        
	}
	pre=head->next;
	for(i=0;i<3;i++)
    {
        printf("[num=%d,score=%d]\n",pre->id,pre->score);
        pre=pre->next;

    }
    return 0;
}
