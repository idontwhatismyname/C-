#include <stdio.h>

int getRightNum(int );

int main(void) {
    int num;
    scanf("%d", &num);
    int after = getRightNum(num);
    if(after == -1)
        printf("Doesn't exist\n");
    else 
        printf("%d\n", after);
    return 0;
}

int getRightNum(int num){
	int i,a,b,c,d;
	for(i=num;i>100;i--){
		a=i/100;
		b=(i/10)%10;
		c=i%10;
		d=a*a*a+b*b*b+c*c*c;		
		if(d==i)
			return d;
	}
	return -1;
}