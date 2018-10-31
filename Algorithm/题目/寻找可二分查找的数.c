#include<stdio.h>
int CompareUp(int Num[],int x,int y);//x当前值，y总冒泡数
int CompareDown(int Num[],int x);
 
int main(void){
	unsigned int N;
	scanf("%u",&N);
	int num[N+1],counter=0;
	for(int i=1;i<=N;i++)
		scanf("%d",&num[i]);
	
	for(int k=1;k<=N;k++){
		
		if(k==1){
			if(CompareUp(num,1,N))
				counter++;}
		else if(k==N)
			if(CompareDown(num,N))
				counter++;
		if(k!=1&&k!=N)
			if(CompareUp(num,k,N)&&CompareDown(num,k))
				counter++;
		}

	printf("%d",counter);
	return 0;
}
int CompareUp(int Num[],int x,int y){
	for(int i=1;i<=y-x;i++){
		if(Num[x]>=Num[x+i])
			break;
		else if(i==y-x)
			return 1;
		}
		return 0;
	}
int CompareDown(int Num[],int x){
	for(int i=1;i<=x-1;i++){
		if(Num[x]<=Num[i])
			break;
		else if(i==x-1)
			return 1;
		}
		return 0;
	}
			
