#include<stdio.h>
#include<math.h>

int main(){
    int alpha[26]={0};
    char ch;
    while((ch=getchar())!='\n') alpha[ch-'a']++;
    int max=alpha[0],min=alpha[0],i;
    for(i=1;i<26;i++){
        if(max<alpha[i]) max=alpha[i];
        if(min>alpha[i]) min=alpha[i];
    }
    int temp=max-min,k=sqrt(temp),status=0;
    for(i=2;i<=k;i++){
        if(temp%i==0){
            status=1;
            break;
        }
    }
    printf("%s\n",status?"Wrong":"Right");
    return 0;    
}