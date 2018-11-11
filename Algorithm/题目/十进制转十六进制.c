#include<stdio.h>
#include<math.h>

int main(){
    int temp,decimal,counter=1,sum=0;
    scanf("%d",&decimal);
    char ch;
    sum=decimal;
    while(decimal=decimal/16)
            counter++;
	while(counter!=0){
        counter--;
		temp=sum/pow(16,counter);
        sum=sum-temp*pow(16,counter);
        if(temp>=10&&temp<=15)
            ch=temp-10+'A';
        else if(temp>=0)
            ch=temp+'0';
        printf("%c",ch);
    }
    return 0;
}
