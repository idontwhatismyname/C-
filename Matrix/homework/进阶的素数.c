#include<stdio.h>
#include<math.h>

int main(void){
	int n,j=1,counter,i;
	scanf("%d",&n);
	while(n-->0){
		
		while(1){
			j++;
			counter=0;
			for(i=1;i<=sqrt(j);i++)
				if(j%i==0)
					counter++;
			if(counter==1&&n!=0){
				printf("%d ",j);
				break;
			}
			else if(counter==1&&n==0){
			
				printf("%d",j);
				break;
			}
			}
	
		}
		
	printf("\n");	
		
	return 0;
}
