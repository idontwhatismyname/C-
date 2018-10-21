#include<stdio.h>

int main(void){
	int length,breadth;
	scanf("%d%d",&length,&breadth);
	while(length<=0||breadth<=0){
		printf("Please enter positive numbers!\n");
		scanf("%d%d",&length,&breadth);
	}
	unsigned int counlen=length,counbre=breadth;
	
	while(counlen>0){
		while(counbre>0){
			if(counlen==length||counlen==1)
				printf("%s","+");
			else
				printf("%s",counbre==breadth||counbre==1?"+":" ");
			counbre--;
		}
		counbre=breadth;
		counlen--;
		puts("");
	}
	return 0;
}
