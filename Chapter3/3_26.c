//Find the Two Smallest Numbers
#include<stdio.h>

int main(void){
	unsigned int counter = 0;
	int number=0,current;
	int Smal=0,SecSmal=0;
	printf("%s","Enter number, -1 to end: ");
	scanf("%d",&number);
	while(number!=-1){
		counter++;
		if(counter==1)
			Smal = number;
		else if(counter==2)
			SecSmal = number;
		if(counter>=2){
		
		if(number<SecSmal)
			SecSmal=number;
		
		if(Smal>SecSmal){
			number=Smal;
			Smal=SecSmal;
			SecSmal=number;
		}
	}
		printf("%s","Enter number, -1 to end: ");
		scanf("%d",&number);
		
	}//end while
	if(counter>=2)
		printf("The smallest number is %d\nThe second smallest number is %d\n",Smal,SecSmal);
	else if (counter==1)
		printf("The smallest number is %d",Smal);
		else 
			printf("No Number!\n");
	return 0;
}
