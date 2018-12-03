#include<stdio.h>

void read(int *memory,int index){
    int num;
    scanf("%d",&num);
    memory[index]=num;
}

void write(int *memory,int index){
    printf("%d\n",memory[index]);
}

void load(int *memory,int index){
    memory[100]=memory[index];
}

void store(int *memory,int index){
    memory[index]=memory[100];
}

void add(int *memory,int index){
    memory[100]+=memory[index];
}

void subtract(int *memory,int index){
    memory[100]-=memory[index];
}

void divide(int *memory,int index){
    memory[100]/=memory[index];
}

void multiply(int *memory,int index){
    memory[100]*=memory[index];
}

int branch(int index){
    return index-1;    
}

int branchneg(int *memory,int index,int curr){
    if(memory[100]<0)
        return index-1;
    else
        return curr;
}

int branchzero(int *memory,int index,int curr){
    if(memory[100]==0)
        return index-1;
    else
        return curr;
}