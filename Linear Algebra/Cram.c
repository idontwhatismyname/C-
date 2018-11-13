#include<stdio.h>
#include<math.h>

void displayMatrix(const int [][4]);
void EnterMatrix(int [][4]);
char ChangeNumintoChar(int);
int determinant(int i,int j,int [][4]);
void Interchange(int r1,int r2,int [][3]);

int main(){
    int i,j;
    printf("Please enter the entry of the matrix as the following format.\n");
    int formats[4][4];
    char ch='a';
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            formats[i][j]=ch++;
    displayMatrix(formats);
    int Mat[4][4];
    EnterMatrix(Mat);
    displayMatrix(Mat);
    int adj[4][4]
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            adj[j][i]=pow(-1,i+j)*determinant(i,j,Mat);
    return 0;
}

void displayMatrix(const int num[][4]){
    int i,j;
    for(i=0;i<=3;i++){
        printf("| ");
        for(j=0;j<=3;j++)
            printf("%c ",num[i][j]);
        printf("|\n");
    }
}

void EnterMatrix(int mat[][4]){
    int i,j;
    for(i=0;i<=3;i++)
        for(j=0;j<=3;j++)
            scanf("%d",&mat[i][j]);
}

char ChangeNumintoChar(int num){
    return num+'0';
}

