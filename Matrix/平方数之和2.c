#include<stdio.h>
#include<math.h>
int main(void){
	unsigned long long n,i,j,p,k,q;
	scanf("%llu",&n);
	for(i=sqrt(n);i>=1;i--){
		j=0;
		p=i*i;
		q=n-i*i;
		k=j*j;
		while(k<q){
			j++;
			if(j>i)
				break;
		}
		if(k==q)
			printf("true\n");
		if(j>i){
			printf("false\n");
			break;
		}
	} 
	
	return 0; 
	}
