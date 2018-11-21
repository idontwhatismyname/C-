#include<stdio.h>
#include<math.h>

int main(){
    int T,i,num;
    scanf("%d",&T);
    int tree[2048]={0};
    int position[2048]={1};
    int MAX=pow(2,T);
    scanf("%d",&tree[0]);
    while(T-->1){
        scanf("%d",&num);
        for(i=0;i<MAX;i++)
            if(num<=tree[i])
                if(position[2*i+1]){
                    i=2*i;
                    continue;
                }
                else{
                    tree[2*i+1]=num;
                    position[2*i+1]=1;
                    break;
                }
            else
                if(position[2*i+2]){
                    i=2*i+1;
                    continue;
                }
                else{
                    tree[2*i+2]=num;
                    position[2*i+2]=1;
                    break;
                }
    }
    for(i=0;i<MAX;i++)
        if(position[i])
            printf("%d\n",tree[i]);
    return 0;
}