#include<stdio.h>
#include<math.h>
int main(void){
	long long n,i,j,p,k,q;
	scanf("%lld",&n);
	
	for(i=sqrt(n);i>=1;i--){
		p=i*i;
		if((n-p)==(unsigned long long)sqrt(n-p)*(unsigned long long)sqrt(n-p)){
			printf("true\n");
			break;
			
		}
		if(i==1)
			printf("false\n");
	}
	if(n==0)
		printf("false\n");	
	
	return 0; 
	}
