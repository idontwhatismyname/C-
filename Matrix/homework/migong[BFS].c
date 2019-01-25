#include<stdio.h>

int list[10001]={0};
int BFS[10000]={0};
int main(){
    int N,M,i,j,counter=1,curr=0,status=0;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
        for(j=0;j<M;j++){
            scanf("%d",&list[counter++]);
        }
    BFS[0]=1;
    while(1){
        if(list[BFS[0]]==0)
            if(curr==0)
                break;
            else{
                for(i=0;i<curr;i++)
                    BFS[i]=BFS[i+1];
                curr--;
            }
        else{
            if(BFS[0]%M!=0&&BFS[0]<(N-1)*M){
                for(i=curr;i>=1;i--)
                    BFS[i+1]=BFS[i];
                BFS[1]=BFS[0]+M;
                BFS[0]=BFS[0]+1;
                curr++;
            }
            else if(BFS[0]<(N-1)*M)
                BFS[0]=BFS[0]+M;
            else if(BFS[0]%M!=0)
                BFS[0]=BFS[0]+1;
            else{
                status=1;
                break;
            }
        }
    }
    if(status)
        printf("OK\n");
    else
        printf("NO\n");
    return 0;
}