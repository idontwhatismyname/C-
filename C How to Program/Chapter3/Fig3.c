#include<stdio.h>

int main(void){
	unsigned int counter=0;
	int total=0,average,grade;
	printf("Enter grade: ");
	while(scanf("%d",&grade)){
		total = total+grade;
		counter ++;
		printf("Enter grade: ");
	}
	average = total / counter;
	printf("Class average is %d",average);
	return 0;	
}
