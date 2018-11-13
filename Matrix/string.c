#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n);
    char string1[10000],string2[10000];
    int i,len1,len2,curcount=0,count=0,a=0;
    while(n--){
        count=0,curcount=0;
        scanf("%s%s",string1,string2);
        len1=strlen(string1),len2=strlen(string2);
        a=0;
        for(i=0;i<len1;i++){
            if(string1[i]==string2[a]){
                curcount++;
                a++;
                if(a>len2-1)
                    a=0;
            }
            else{
                if(curcount>count)
                    count=curcount;
                a=0;
                curcount=0;
            }
        }
        if(string1[i-1]==string2[(a==0?len2-1:a-1)])
            if(curcount>count)
                count=curcount;
        printf("%d\n",count);
    }
    return 0;
}