#include <stdio.h>
#define MaxLen 1010

void swap(char *a,char *b);
int main()
{
    char a[MaxLen], b[MaxLen];
    scanf("%s", a);
    scanf("%s", b);
    swap(a, b);
    printf("%s\n%s\n", a, b);

    return 0;
}
void swap(char *a, char *b){
    int i;
    char temp;
    for(i=0;i<MaxLen;i++){
        temp=*a;
        *a=*b;
        *b=temp;
        a++;b++;
    }
}