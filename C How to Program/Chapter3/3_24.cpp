#define TENS 10
#include<stdio.h>

int main(void){
	float a = TENS;
	int counter=1;
	printf("N\t\t0.25*N\t\t0.50*N\t\t0.75*N\n");
	while(counter<=10){
		printf("%f\t%f\t%f\t%f\n",a,0.25*a,0.50*a,0.75*a);
		a += TENS;
		counter++;
	}	
	return 0;
} 
