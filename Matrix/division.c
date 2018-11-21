#include<stdio.h>
#include<string.h>

int main(){
    int T,i,len,total,counter=0;
    int result[100]={0};
    char num[100];
    scanf("%d",&T);
    while(T--){
        counter=0;
        scanf("%s",num);
        len=strlen(num);
        for(i=0;i<len;i++)
            num[i]-=48;
        for(i=0;i<len-1;i++){
            if(num[i]<3){
                total=num[i]*10+num[i+1];
                result[counter++]=total/3;
                num[i+1]=total%3;
            }
            else{
                result[counter++]=num[i]/3;
                num[i+1]+=(num[i]%3)*10;
            }
        }
        result[counter]=num[len-1]/3;
        if(result[counter]==0&&counter!=0)
            counter--;
        for(i=0;i<=counter;i++)
            printf("%d",result[i]);
        puts("");
    }
    return 0;

}