#include<stdio.h>

int main(void){
	int i,i1,i2,i3,i4,i5;
	printf("%s","Please enter a five-digit number :");
	scanf("%d",&i);
	i1=i/10000;
	i2=(i%10000)/1000;
	i3=(i%1000)/100;
	i4=(i%100)/10;
	i5=i%10;
	printf("%d\t%d\t%d\t%d\t%d",i1,i2,i3,i4,i5);
}//end main
