#include<stdio.h>

char str[50]={0};

int main(){
    char ch;
    int counter=-1,i,j,status=0;
    while((ch=getchar())!='\n'){
        if(ch=='('||ch=='['||ch=='{')
            str[++counter]=ch;
        else if(ch==')'||ch==']'||ch=='}'){
            status=1;
            for(i=counter;i>=0;i--)
                if((ch==')'&&str[i]=='(')||(ch==']'&&str[i]=='[')||(ch=='}'&&str[i]=='{')){
                    status=0;
                    for(j=i;j<counter;j++)
                        str[j]=str[j+1];
                    str[counter--]=0;
                    break;
                }
            if(status)
                break;
        }
    }
    printf("%s\n",str[0]==0?"Yes":"No");
    return 0;    
}