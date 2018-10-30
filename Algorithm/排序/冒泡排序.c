#include<stdio.h>

int main(void){
	int times,i,sum,k,j,temp,q,counter;
	scanf("%d",&times);
	int num[30]={0};
	for(k=1;k<=times;k++){
		scanf("%d",&sum);
		for(i=0;i<sum;i++){
			scanf("%d",&num[i]);
		}
		for(i=1;i<=sum-1;i++){
			counter=0;
			for(j=0;j<sum-i;j++){
				if(num[j]>num[j+1]){
					temp=num[j];
					num[j]=num[j+1];
					num[j+1]=temp;
					counter++;
				}
				for(q=0;q<=sum-1;q++)
					printf("%d ",num[q]);
				printf("\n");
				}
		    if(counter==0)
		    	break;
		}
	}
	return 0;
}