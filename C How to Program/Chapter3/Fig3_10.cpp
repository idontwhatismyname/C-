#include<stdio.h>

int main(void){
	int StuNum,counter = 1,num1 = 0,num2 = 0;
	while(counter<=10){
		printf("%s","Enter Result (1=pass ,2=fail): ");
		scanf("%d",&StuNum);
		if(StuNum==1||StuNum==2){
			if(StuNum==1){
				num1++;
				counter++;
			}
			else{
				num2++;
				counter++;
			}
		}//end if
		else
			puts("Wrong enter");
			
	}//end while
	printf("Passed %d\nFailed %d\n",num1,num2);
	if(num1>=8)
		printf("%s","Bonus to instructor!\n");
	return 0;
}//end main
