#include<stdio.h>

int total[201]={0};

int main(){
    char ch;
    int counter1=0,counter2=0,curr,i,j,mul;
    int a[100];
    int b[100];
    while((ch=getchar())!='\n')
        a[counter1++]=ch-'0';
    while((ch=getchar())!='\n')
        b[counter2++]=ch-'0';
    counter1--,counter2--;
    for(i=0;i<=counter1;i++)
        for(j=0;j<=counter2;j++){
            mul=a[counter1-i]*b[counter2-j];
            if(mul/10)
                total[i+j+1]+=mul/10;
            mul%=10;            
            total[i+j]+=mul;
            if(total[i+j]/10){
                total[i+1+j]+=total[i+j]/10;
                total[i+j]%=10;
            }
        }
    if(total[i+j-1]==0)
        i--;
    int k=i+j-1;
    for(i=k;i>=0;i--)
        printf("%d",total[i]);
    puts("");
	return 0;
}