#include<stdio.h>
#include<stdlib.h>
#include"instruction.h"

int main(){
    int *memory=(int*)malloc(101*sizeof(int));
    int i=0;
    for(i=0;i<101;i++)
        memory[i]=0;
    int instru,lo,counter=0,count=0;
    scanf("%d",&memory[0]);
    while(memory[counter]!=-1){
        scanf("%d",&memory[++counter]);
    }
    while(count<counter){
        instru=memory[count]/100;
        lo=memory[count]%100;
        switch(instru){
            case 10:read(memory,lo);break;
            case 11:write(memory,lo);break;
            case 20:load(memory,lo);break;
            case 21:store(memory,lo);break;
            case 30:add(memory,lo);break;
            case 31:subtract(memory,lo);break;
            case 32:divide(memory,lo);break;
            case 33:multiply(memory,lo);break;
            case 40:count=branch(lo);break;
            case 41:count=branchneg(memory,lo,count);break;
            case 42:count=branchzero(memory,lo,count);break;
            case 43:count=counter;break;
            case 0:printf("%d\n",memory[count]);
        }
        count++;
    }
    free(memory);
    return 0;
}