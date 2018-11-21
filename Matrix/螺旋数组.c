#include<stdio.h>
int num[100][100];
int main(){
    int n;
	scanf("%d",&n);
	int i=0,j=0,k=1,jcount=1,icount=0,q=0,count1=1,count2;
	int temp=n*n;
	while((temp/=10))
		count1++;	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			num[i][j]=0;
	i=0,j=0;
	while(k<=n*n){
		num[i][j]=k++;				
		i=i+icount;
		j=j+jcount;
		if(i>n-1||i<0||j>n-1||j<0||num[i][j]!=0){
			i=i-icount;
			j=j-jcount;	
			q=(q+1)%4;
			switch(q){
				case 1:jcount=0;icount=1;break;
				case 2:jcount=-1;icount=0;break;
				case 3:jcount=0;icount=-1;break;
				case 0:jcount=1;icount=0;
			}
			i+=icount;	
			j+=jcount;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			temp=num[i][j];
			count2=1;			
			if(j==n-1)
				count2++;			
			while((temp/=10))
				count2++;			
			printf("%d",num[i][j]);
			while(count2++<(count1+1))
				printf(" ");
		}
		puts("");
	}
	return 0;
}
