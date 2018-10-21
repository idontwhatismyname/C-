#include<stdio.h>

unsigned long long factorial(int n){
	int counter =n;
	unsigned long long sum =1;
	while(counter>=1){
		sum *= (unsigned long long)counter;
		counter--;
	}
	return sum;
}

int main(void){
	unsigned int x,n;
	scanf("%d",&x);
	int counter = 1,counter1=1;
	double e=1,y=1;
	while(counter<=16){
		e += (double)y/factorial(counter++);//y的值和1的值不一样 
		
	}
	while(counter1++<=x)
		y*=e;
	printf("%lf",y);
	return 0;
}
