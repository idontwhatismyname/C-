#include<stdio.h>

int main(void){
	unsigned int num,ten,thou,hund,tenth,first;
	scanf("%d",&num);
	first = num%10;
	tenth = num/10%10;
	hund = num/100%10;
	thou = num/1000%10;
	ten = num/10000;
	if(first==ten&&tenth==thou)
		printf("It is a palindrome!\n");
	else
		printf("It is not a palindrome!\n");
	return 0;
	
}
