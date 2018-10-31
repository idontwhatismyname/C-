#include<stdio.h>
int decided(int pos[101],int x,int y ,int z);

int main(void){
	int counter =0,curr=0,k;
	int type[101],pre[101];
	long input[100];
	
	while(scanf("%d",&input[counter])){
	if(input[counter]!=-1){
		curr=input[counter++];
		k=1;
		pre[k]=curr%10;
		curr=curr/10;
		while(curr!=0){
			pre[++k]=curr%10;
			curr/=10;
		}
		type[counter]=decided(pre,k/2,0,k);
	}
	else
		break;
	}
	for(int i=1;i<=counter;i++)
		printf("%s",type[i]==1?"Yes\n":"No\n");
	return 0;
} 
int decided(int pos[101],int x,int y,int z){//x是比较的总次数，y是现在比较的次数，z总共位数 
	if(x!=y){
		y=y+1;
		if(pos[z-y+1]==pos[y])
			return decided(pos,x,y,z);
		else
			return 0;
	} 
	else 
		return 1;
	}
