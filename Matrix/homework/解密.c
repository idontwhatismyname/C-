#include<stdio.h>
#include<string.h>
const int MAX =1000000;
char sen[MAX];
int main(void){
    int i,temp,times,counter;
    scanf("%d",&times);
    char ch,curr=0;
    ch=getchar();
    while(times--){
        ch=getchar();
        counter=0;
        while(ch!=10 || counter==0){
            sen[counter++]=ch;
            ch=getchar();
        }
        for(i=0;i<counter;i=i+2){
            if(sen[i]>=65&&sen[i]<=70)
                temp=(sen[i]-55)*16;
            else 
                temp=(sen[i]-48)*16;
            if(sen[i+1]>=65&&sen[i+1]<=70)
                temp=temp+(sen[i+1]-55);
            else
                temp=temp+sen[i+1]-48;
            if(temp>=0&&temp<=25)
                temp+=65;
            else if(temp>=26&&temp<=51)
                temp+=(97-26);
            printf("%c",temp);
                if(temp==59)
            printf("\n");
            }
    }
    return 0;
}