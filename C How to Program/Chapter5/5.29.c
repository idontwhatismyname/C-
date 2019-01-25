#include<stdio.h>

int lcm(int num1,int num2);

int main(void){
	int num1,num2;
	scanf("%d%d",&num1,&num2);
	printf("%d\n",lcm(num1,num2));
	return 0;
}

int lcm(int num1,int num2){
	int mult=num1*num2;
	int curr=0;
	while(num2!=0){
		if(num1>num2){
			curr=num1-num2;
			num1=num2;
			num2=curr;
		}
		else {
			curr=num2-num1;
			num2=curr;
		}
	}
	return mult/num1;
}
