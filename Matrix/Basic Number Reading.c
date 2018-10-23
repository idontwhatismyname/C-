#include<stdio.h>
#include<math.h>

int main(void){
	unsigned long long num1=0,num2=0,num;
	int times,base,i,counter=0;
	scanf("%d%d",&times,&base);
	char ch;
	ch=getchar();
	for(i=1;i<=times;i++){
		counter=0;
		num1=0,num2=0;
		
		scanf("%c",&ch);
		while(ch!=10){
			ch=ch-48;
			num1=num1+(unsigned long long)pow(base,counter++)*ch;
			num2=num2*base+ch;
			scanf("%c",&ch);
		}
		
		printf("%d %d\n",num2,num1);
	}
	return 0;
}
