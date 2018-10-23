#include<stdio.h>

int main(void){
	unsigned long long y,days,i,ycounter=0;
	int m,d,mcounter,k;
	scanf("%llu%d%d",&y,&m,&d);
	y=y-1; 
	ycounter=y/4-y/100+y/400;
	days=y*365+ycounter;
	
	m-=1;
	k=m;
	while(k>=0){
	if(k==1||k==3||k==5||k==7||k==8||k==10)
		mcounter++;
	else if(k==2&&(y+1)%4!=0)
		mcounter-=2;
	else if(k==2&&(y+1)%4==0)
		mcounter--;
	k--;
}
	days=days+mcounter+m*30+d-1;
	printf("%d\n",days%7+1);
		
}
