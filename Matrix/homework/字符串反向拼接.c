#include<stdio.h>
#define MAX 40
char s[MAX];
char p[MAX];

int main(void){
    int times,i,counter1,j,counter2;
    char ch;
    scanf("%d",&times);
    ch=getchar();
    for(j=1;j<=times;j++){
        counter1=0,counter2=0;
        while((ch=getchar())!=10&&ch!=32)
            s[counter1++]=ch;
        while((ch=getchar())==32||ch==10)
            ch=0;
            p[counter2++]=ch;
        while((ch=getchar())!=10&&ch!=32)
            p[counter2++]=ch;
        for(i=0;i<counter1;i++)
            printf("%c",p[counter2-1-i]);
        for(i=0;i<counter1;i++)
            printf("%c",s[counter1-i-1]);
        printf("\n");
    }
    return 0;
}