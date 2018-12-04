#include<stdio.h>
int people[100][100]={0};//0是不可访问,1是可访问    0是白色，1是灰色，2是黑色
int main(){
    int N,M,T,i,a,b,j,status[100]={0},success,counter=0,curr;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d%d",&a,&b);
        people[a][b]=1;
        people[b][a]=1;
    }
    scanf("%d",&T);
    while(T--){
        success=0;
        scanf("%d%d",&a,&b);
        status[a]=1;
        curr=a;
        counter=1;
        do{
            for(j=0;j<N;j++)
                if(people[curr][j]&&status[j]!=2){ 
                    status[j]=1;
                    counter++;
                }
            status[curr]=2;
            counter--;
            for(j=0;j<N;j++)
                if(status[j]==1){
                    curr=j;
                    break;
                }
            if(status[b]==1){
                success=1;
                break;
            }
        }while(counter>0);
        if(success)
            printf("Yes\n");
        else
            printf("No\n");
        for(i=0;i<N;i++)
            status[i]=0;
    } 
    return 0;
}