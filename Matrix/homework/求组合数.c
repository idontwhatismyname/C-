#include<stdio.h>
int combine(int, int);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d", combine(m, n));
    return 0;
}

int combine(int m,int n){
	if(n==m||n==0)
		return 1;
	else if(n==1)
		return m;
	else
		return combine(m-1,n)+combine(m-1,n-1);
}
