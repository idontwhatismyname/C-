#include <stdio.h>

int compare(const int, const int, const int, const int);

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", compare(a, b, c, d));
}

int compare(const int a, const int b , const int c, const int d){
	long long num1=(long long)a*d,num2=(long long)b*c;
	if((num1-num2)<0)
		return -1;
	else if((num1-num2)==0)
		return 0;
	else
		return 1;
} 