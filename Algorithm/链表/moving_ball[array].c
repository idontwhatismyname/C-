#include<stdio.h>

int lft[500001];
int rgt[500001];

int main(){
	int n,m,t,i,op,ball_x,ball_y,front,curr,change,temp;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		lft[0]=0;rgt[0]=1;
		for(i=1;i<=n+1;i++){
			lft[i]=i-1;
			rgt[i]=i+1;
		}
		while(m--){
			scanf("%d",&op);
			if(op!=4){
				scanf("%d%d",&ball_x,&ball_y);
				if(op==1&&lft[ball_y]==ball_x) continue;
				else if(op==2&&rgt[ball_y]==ball_x) continue;
				if(op==1){
					rgt[lft[ball_x]]=rgt[ball_x];
					lft[rgt[ball_x]]=lft[ball_x];
					lft[ball_x]=lft[ball_y];
					rgt[lft[ball_y]]=ball_x;
					lft[ball_y]=ball_x;
					rgt[ball_x]=ball_y;
				}
				else if(op==2){
					rgt[lft[ball_x]]=rgt[ball_x];
					lft[rgt[ball_x]]=lft[ball_x];
					rgt[ball_x]=rgt[ball_y];
					lft[rgt[ball_y]]=ball_x;
					rgt[ball_y]=ball_x;
					lft[ball_x]=ball_y;
				}
				else if(op==3){
					rgt[lft[ball_x]]=ball_y;
					lft[rgt[ball_x]]=ball_y;
					rgt[lft[ball_y]]=ball_x;
					lft[rgt[ball_y]]=ball_x;
					temp=rgt[ball_x];
					rgt[ball_x]=rgt[ball_y];
					rgt[ball_y]=temp;
					temp=lft[ball_x];
					lft[ball_x]=lft[ball_y];
					lft[ball_y]=temp;
				}
			}
		}
		front=rgt[0];
		printf("%d ",front);
		curr=front;
		for(i=2;i<=n;i++){
			printf("%d ",rgt[curr]);
			curr=rgt[curr];
		}
		puts("");
	}
	return 0;
}
