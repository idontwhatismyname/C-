#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node *lft;
	struct node *rgt;
}Node;
Node *ball[5000001];
int main(){
	int t,n,m,i,op,ball_x,ball_y,front;
	Node *curr;
	scanf("%d",&t);
	ball[0]=(Node*)malloc(sizeof(Node *));
	ball[0]->data=0;
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n+1;i++){
			ball[i]=(Node *)malloc(sizeof(Node*));
			ball[i]->data=i;
			ball[i]->lft=ball[i-1];
			ball[i-1]->rgt=ball[i];
		}
		while(m--){
			scanf("%d%d%d",&op,&ball_x,&ball_y);
			(ball[ball_x]->lft)->rgt=ball[ball_x]->rgt;
			(ball[ball_x]->rgt)->lft=ball[ball_x]->lft;
			if(op==1){
				(ball[ball_y]->lft)->rgt=ball[ball_x];
				ball[ball_x]->lft=ball[ball_y]->lft;
				ball[ball_x]->rgt=ball[ball_y];
				ball[ball_y]->lft=ball[ball_x];
			}
			else{
				(ball[ball_y]->rgt)->lft=ball[ball_x];
				ball[ball_x]->rgt=ball[ball_y]->rgt;
				ball[ball_x]->lft=ball[ball_y];
				ball[ball_y]->rgt=ball[ball_x]; 
			}
		}
		for(i=1;i<=n;i++)
			if(ball[i]->lft->data==0){
				front=i;
				break;
			} 
		curr=ball[front];
		for(i=1;i<=n;i++){
			printf("%d ",curr->data);
			curr=curr->rgt;
		}
		puts("");
		for(i=1;i<=n+1;i++)
			free(ball[i]);
	}
	free(ball[0]);
	return 0;
}
