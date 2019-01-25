#include<stdio.h>

int main(void){
	unsigned int BinNum,Curr,DecNum = 0,PosVal;
	PosVal=1;
	scanf("%d",&BinNum);
	Curr=BinNum;
	while(Curr!=0){
		DecNum += Curr%10*PosVal;
		PosVal *=2;
		Curr /= 10;
	}
	printf("%d's decimal number is %d.\n",BinNum,DecNum);
	return 0;
}
