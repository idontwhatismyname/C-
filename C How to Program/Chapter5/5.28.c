#include<stdio.h>
int ChangeintoUp(char a);
int ChangeintoDown(char b);

int main(void){
	char ch;
	while((ch=getchar())!=EOF)
		if(ch>='A'&&ch<='Z')
			printf("%c",ChangeintoDown(ch));
		else if(ch>='a'&&ch<='z')
			printf("%c",ChangeintoUp(ch));
		else
			printf("\nWrong Enter\n");
	return 0;
}

int ChangeintoUp(char ch){
	return ch-32;
}

int ChangeintoDown(char ch){
	return ch+32;
}
