#include<stdio.h>
#include<math.h>

int main(void){
	int M,i,j=0,total;
	scanf("%d",&M);
	for(i=6;i<=M;i++){
		total=0;
		for(j=1;j<=sqrt(i);j++){
			if(j==sqrt(i))
				total=total+j;
			else if(i%j==0)
				total=total+j+(i/j);
			if(total/2>i){
				total=0;
				break;
			}}
		if(total/2==i)
			printf("%d\n",i);
	}
	return 0;
}
