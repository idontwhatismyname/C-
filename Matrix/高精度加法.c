#include<stdio.h>

int main(void){
    char ch;
    int a[100]={0},b[100]={0},sum[100]={0};
    int counter1=0,counter2=0,i,j;
    while((ch=getchar())!=10)
        a[counter1++]=ch-48;
    while((ch=getchar())!=10)
        b[counter2++]=ch-48;
    for(i=0;i<(counter1>counter2?counter1:counter2);i++){
        sum[i]=sum[i]+(counter1-i-1>=0?a[counter1-i-1]:0)+(counter2-i-1>=0?b[counter2-i-1]:0);
        if(sum[i]>=10){
            sum[i]-=10;
            sum[i+1]++;
        }
    }
    if(sum[i]==0)
        i--;
    for(j=i;j>=0;j--)
        printf("%d",sum[j]);
    printf("\n");
    return 0;
}