#include<stdio.h>

int main(){
	int i,counter=0;
	char words;
	char ch[26]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	scanf("%c",&words);
	while(ch[counter++]!=words);
	printf("%c\n",ch[counter]);
	return 0;
}
