#include<stdio.h>
#include<math.h>

void roundToInteger(double num);
void roundToTenths(double num);
void roundToHundreths(double num);
void roundToThousandths(double num); 

int main(void){
	double number;
	printf("Please enter the number you need to be rounded:");
	scanf("%lf",&number);
	printf("Please select your choice (while a equal to roundToInteger and b equal to roundToTenths c equal to roundToHundreths d equal to roundToThousandths):");
	char ch;
	ch=getchar();
	while((ch=getchar())!=EOF){
		switch (ch){
			case 'a':roundToInteger(number);
					 break;
			case 'b':roundToTenths(number);
					 break;
			case 'c':roundToHundreths(number);
					 break;
			case 'd':roundToThousandths(number);
					 break;
			default :while(1){
						printf("Wrong Enter!\n");
						printf("Please select your choice (while a equal to roundToInteger and b equal to roundToTenths c equal to roundToHundreths d equal to roundToThousandths):");
						ch=getchar();
						if(ch=='a'||ch=='b'||ch=='c'||ch=='d')
							break;
						ch=getchar();
						}
					}
			ch=getchar();
			printf("Please select your choice (while a equal to roundToInteger and b equal to roundToTenths c equal to roundToHundreths d equal to roundToThousandths):");
		}
	return 0;
}

void roundToInteger(double num){
	printf("%.0f\n",floor(num +.5));
}

void roundToTenths(double num){
	printf("%.1f\n",floor(num*10 +.5)/10); 
}

void roundToHundreths(double num){
	printf("%.2f\n",floor(num*100 +.5)/100); 
}

void roundToThousandths(double num){
	printf("%.3f\n",floor(num*1000 +.5)/1000); 
}
