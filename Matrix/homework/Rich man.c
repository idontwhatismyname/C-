#include <stdio.h>

int main(void){
	int times,i,total1=0,num;
	unsigned long long total2=0;	
	scanf("%d",&times);
	for(i=1;i<=times;i++){
		scanf("%d",&num);
		total1=total1+num;
		total2=total2+(unsigned long long)num*num;
	}
	double e=(double)total1/times;
	double d=(double)total2/times-(double)total1*total1/(times*times);
	printf("%.2f %.2f\n",e,d);
	return 0;
}