#include <stdio.h>

int fibo(int );

int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
        printf("%d\n",fibo(a));
    return 0;
}

int fibo(int num){
	if(num!=2&&num!=1&&num!=0)
		return fibo(num-1)+fibo(num-2);
	else 
		return 1;
}