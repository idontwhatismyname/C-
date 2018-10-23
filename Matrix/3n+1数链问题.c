#include<stdio.h>

int main(void){
	int num1,num2,counter1=1,counter2=1,i,temp1;
	scanf("%d%d",&num1,&num2);
		temp1=num1;
		while(temp1!=1){
		if(temp1%2==0)
			temp1/=2;
		else
			temp1=temp1*3+1;
		counter1++;
	}
	counter2=counter1;
	for(i=1;i<=num2-num1;i++){
		temp1=i+num1;
		counter1=1;
	while(temp1!=1){
		if(temp1%2==0)
			temp1/=2;
		else
			temp1=temp1*3+1;
		counter1++;
	}
	if(counter1>counter2)
		counter2=counter1;

}
	printf("%d\n",counter2);
	return 0;
}
