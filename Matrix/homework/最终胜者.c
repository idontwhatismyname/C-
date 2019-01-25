#include<stdio.h>
#define MAX 101
int main(void){
    int k,times,i,n,m,j,counter,q;
    int child[MAX]={0};
    scanf("%d",&times);
    for(i=1;i<=times;i++){
        k=1;
        scanf("%d%d",&n,&m);
        counter=n;
        k=1;
        for(j=1;j<=n;j++)
            child[j]=j;
        for(j=1;j<=(n-1)*m;j++,k++){
            if(k>counter)
                k=1;
            if(j%m==0&&j!=0){
                for(q=k;q<counter;q++)
                    child[q]=child[q+1];
                counter--;
                k--;
            }
            
        }

        printf("%d\n",child[1]);
    }
    return 0;
}