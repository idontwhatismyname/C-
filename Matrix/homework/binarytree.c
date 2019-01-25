#include<stdio.h>
#include<math.h>

int position[2048]={1};
int tree[2048]={0};
void binarytree(int num,int i);

int main(){
    int T,i,num;
    scanf("%d",&T);
    scanf("%d",&tree[0]);
    for(i=1;i<T;i++){
        scanf("%d",&num);
        binarytree(num,0);
    }
    int k=pow(2,T)-1;
    for(i=0;i<k;i++)
        if(position[i])
            printf("%d\n",tree[i]);
    return 0;
}

void binarytree(int num,int i){
    if(num<=tree[i])
        if(position[2*i+1])
            binarytree(num,2*i+1);
        else{
            tree[2*i+1]=num;
            position[2*i+1]=1;
        }
    else
        if(position[2*i+2])
            binarytree(num,2*i+2);
        else{
            tree[2*i+2]=num;
            position[2*i+2]=1;
        }
}