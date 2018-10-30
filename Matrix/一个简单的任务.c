#include <stdio.h>

int main()
{
    int t,n,q;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        find_o_p(n);
    }
    return 0;
}

void find_o_p(int num){
	int counter=0;	
	while(num%2==0){
			num/=2;
			counter++;
		}
		printf("%d %d\n",num,counter);
	}
	
