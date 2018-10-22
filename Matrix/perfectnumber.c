#include<stdio.h>
#include<math.h>

int main(void){
	int M,i,j=0,total;
	scanf("%d",&M);
	
	for(i=6;i<=M;i++){
		total=0;
		j=1;
		for(j=1;j<=sqrt(i);j++){
			if(i%j==0)
				if(j==sqrt(i)||j==1)
					total+=j;
				else  
					total+=j+i/j;
			
		}
		if(total==i)
			printf("%d\n",i);
	}
	return 0;
}
