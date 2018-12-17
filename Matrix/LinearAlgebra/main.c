#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct DATABASE{
    int numer;//分子
    int deno;//分母
}database;

typedef struct MATRIX{
    database **data;//将分子和分母分成两个东西进行储存 后面要全部修改
    int row,col;
}matrix;

/*

int Determinant(const matrix mat);
/*Elementary Row Operation*/
/*void Replacement(const int row1[],int row2[],const int col,const double multiple);
void Interchange(int *row1,int *row2,const int col);
void Scaling(int *row,const double scales,const int col);
void RowReduceToRowReduceEchelonForm(matrix *mat);
*/
matrix *InitializeMatrix();
void ReleaseMatrix(matrix *mat);
matrix *ReadMatrix();
database read();
void PrintMatrix(const matrix* const mat);

int main(){
    matrix *mat=ReadMatrix();
    PrintMatrix(mat);
    ReleaseMatrix(mat);
    return 0;
}

void PrintMatrix(const matrix* const mat){
    int i,j;
    for(i=1;i<=mat->row;i++){
        for(j=1;j<=mat->col;j++){
            if(mat->data[i][j].deno==1)
                printf("%d ",mat->data[i][j].numer);
            else
                printf("%d/%d ",mat->data[i][j].numer,mat->data[i][j].deno);
        }
        puts("");
    }
}

database read(){
    char ch;
    bool status=0;
    database data={0,1};
    int curnum=0;
    while((ch=getchar())!=' '&&ch!='\n'){
        if(ch=='/'){
            status=1;
            data.numer=curnum;
            curnum=0;
            while((ch=getchar())!=' '&&ch!='\n'){
                curnum+=curnum*10+(ch-'0');
            }
            data.deno=curnum;
            break;
        }
        curnum+=curnum*10+(ch-'0');
    }
    if(status==0) data.numer=curnum;
    return data;
}
matrix* ReadMatrix(){
    int row,col,i,j;
    scanf("%d%d",&row,&col);
    getchar();
    matrix *mat=InitializeMatrix(row,col);
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++)
            mat->data[i][j]=read();
    }
    return mat;
}

void ReleaseMatrix(matrix *mat){
    int i,j;
    for(i=0;i<=mat->row;i++){
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

matrix *InitializeMatrix(int Row,int Col){
    matrix *mat=(matrix*)malloc(sizeof(matrix));
    int i,j;
    mat->row=Row,mat->col=Col;
    mat->data=(database**)malloc((Row+1)*sizeof(database*));
    mat->data[0]=(database*)malloc(sizeof(database)*(Col+1));
    for(i=1;i<=Row;i++){
        mat->data[i]=(database*)malloc(sizeof(database)*(Col+1));
        for(j=1;j<=Col;j++)
            mat->data[i][j].deno=1;
    }
    return mat;
}
/*
void RowReduceToRowReduceEchelonForm(matrix *mat){
    int i;
    for(i=2;i<=mat->row;i++){
        Replacement(mat->data[1],mat->data[i],)
    }
}

void Replacement(const int row1[],int row2[],const int col,const double multiple){
    /*row2 is the row which will be replaced
    int i;
    for(i=1;i<=col;i++)
        row2[i]+=row1[i]*multiple;
}

void Interchange(int *row1,int *row2,const int col){
    int i,temp;
    for(i=1;i<=col;i++){
        temp=row1[i];
        row1[i]=row2[i];
        row2[i]=temp;
    }
}

void Scaling(int *row,const double scales,const int col){
    int i;
    for(i=1;i<=col;i++)
        row[i]*=scales;
}

int Determinant(const matrix mat){
    if(mat.row!=mat.col){
        puts("WRONG!It is not a square matrix!");
        return  ;
    }
    int i
}


*/