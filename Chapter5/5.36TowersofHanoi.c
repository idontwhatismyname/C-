#include<stdio.h>
#include<stdbool.h>
int counter=0;
void TowersofHanoi(int num,int initpeg,int movpeg,int temphold); 

int main(void){
	int n,movpeg;
	printf("Please enter the tower you need to move:");
	scanf("%d",&n);
	printf("Please enter the peg you need to move to:");
	scanf("%d",&movpeg);
	TowersofHanoi(n,1,movpeg,movpeg==2?3:2);
	printf("%d\n",counter);
	return 0;
}

void TowersofHanoi(int num,int initpeg,int movpeg,int temphold){
	counter++;
	if(num!=1){
		TowersofHanoi(num-1,initpeg,temphold,movpeg);
		printf("%d -> %d\n",initpeg,movpeg);
		TowersofHanoi(num-1,temphold,movpeg,initpeg);
	}
	else
		printf("%d -> %d\n",initpeg,movpeg);
	}
	 
	
