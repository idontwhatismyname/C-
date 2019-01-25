#include<stdio.h>

int main(void){
	int n,k,num1,num2,a,b,c,d,e,f;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		e=a*d+b*c;
		f=b*d;
		num1=e;
		num2=f;
		if(num1<num2){
			k=num1;
			num1=num2;
			num2=k;
		}
			
		while(num2){
		
			num1=num1-num2;
		if(num1<num2){
			k=num1;
			num1=num2;
			num2=k;
		}
	}
		e=e/num1;
		f=f/num1;
		printf("%d %d\n",e,f);
			
		}
	return 0;	
}
