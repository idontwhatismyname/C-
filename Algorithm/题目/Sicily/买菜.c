#include<stdio.h>
int main(){
	char time[1000000]={0};
	int n,i,a,b,j,sum=0;
	scanf("%d",&n);
	for(i=0;i<2*n;i++){
		scanf("%d%d",&a,&b);
		for(j=a;j<b;j++)
			time[j]++;
	}
	for(i=0;i<1000000;i++)
		if(time[i]==2) sum++;
	printf("%d",sum);
	return 0;
}

