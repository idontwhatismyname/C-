#include<stdio.h>

int map[100][100];
void migong(int N,int M,int n,int m,int *a);
int main(){
    int N,M,i,j;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            scanf("%d",&map[i][j]);
    int k=-1;
    migong(N,M,0,0,&k);
    if(k==1)
        printf("OK\n");
    else
        printf("NO\n");    
}

void migong(int N,int M,int n,int m,int *a){
    if(m+1<=M&&map[n][m+1]!=0)
        migong(N,M,n,m+1,a);
    if(n+1<=N&&map[n+1][m]!=0)
        migong(N,M,n+1,m,a);
    if(m==M&&n==N)
        *a=1;
}