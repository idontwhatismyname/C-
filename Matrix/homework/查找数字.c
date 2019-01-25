#include<stdio.h>
#define MAX 200000
int num[MAX]={0};
int main(void){
    int times,j,i,k,total,key;
    scanf("%d",&times);
    for(i=1;i<=times;i++){
        scanf("%d",&total);
        for(j=0;j<total;j++)
            scanf("%d",&num[j]);
        scanf("%d",&key);
        for(k=0;k<total;k++){
            if(num[k]==key){
                printf("%d",k);
                break;
            }
        }
        if(k==total)
            printf("No\n");
    }
    return 0;
}