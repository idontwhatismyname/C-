#include<stdio.h>

int main(void){
	int n,line,i;
	scanf("%d",&n);
	line=2*n-1;
	for(i=1;i<=n;i++){
		for(int u=1;u<=line;u++){
			if(u<=line-i+1&&u>i-1)
				printf("#");
			else
				printf(" ");
			
		}
		printf("\n");
	}
	return 0;
}
