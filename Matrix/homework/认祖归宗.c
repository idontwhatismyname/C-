#include<stdio.h>

int main(){
    int N,M,peo,i,q;
    scanf("%d%d",&N,&M);
    int ancestor[N];
    int k=M;
    for(i=0;i<N;i++)
        ancestor[i]=-1;
    while(k--){
        scanf("%d",&peo);
        scanf("%d",&ancestor[peo]);
    }
    for(i=0;i<=N-1;i++){
        q=i;
        while(ancestor[q]!=-1){
            q=ancestor[q];
            ancestor[i]=q;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&peo);
        if(ancestor[peo]==-1)
            printf("Ancestor\n");
        else
            printf("%d\n",ancestor[peo]);
    }
    return 0;
}