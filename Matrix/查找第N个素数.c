#include<stdio.h>
#include<math.h>
unsigned int sushu[1000001]; 
int main(void){
    unsigned int times,i,num=3,curr=1,no,j;
    sushu[1]=2;
    scanf("%d",&times);
    for(i=1;i<=times;i++){
        scanf("%d",&no);
        while(curr<no){
            for(j=2;j<=curr;j++)
              if(num<sushu[j]*sushu[j])
                break;
              else if(num%sushu[j]==0){
                    j=1;
                    num+=2;
                    continue;
                }
            sushu[++curr]=num;
            num+=2;
            }
        printf("%u\n",sushu[no]);
    }
    return 0;
}
