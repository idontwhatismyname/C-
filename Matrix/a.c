#include<stdio.h>

int main(void){
    int times,i,num;
    scanf("%d",&times);
    char ch=getchar();
    for(i=1;i<=times;i++){
        while((ch=getchar())!=10){
            if(ch>='A'&&ch<='Z')
                num=ch-65;
            else if(ch>='a'&&ch<='z')
                num=ch-97+26;
            else 
                num=ch;
            if(num<16)
                printf("0");
            printf("%X",num);
        }
        printf("\n");
        ch=0;
        
    }
    return 0;
}