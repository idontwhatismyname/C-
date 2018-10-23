#include<stdio.h>
int main(void){
	int n,k,q;
	unsigned long long curr, total,former,cur,num1,num2;
	
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		scanf("%llu",&former);
		total=former;
		k=k-1;
		
		while(k--){
			scanf("%llu",&curr);

			num1=former>curr?former:curr;
			num2=former<curr?former:curr;
			
			while(num2){
				num1=num1%num2;
				if(num2>num1){
					cur=num1;
					num1=num2;
					num2=cur;
				}
			}
			total=total*curr/num1;
			former=total;
		
		}
		printf("%llu\n",total);
	}
	return 0;	
}
