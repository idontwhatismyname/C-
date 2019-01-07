#include"header.h"

void ui(){
    char ch;
    puts("Welcome to my Linear Algebra Package!");
    puts("-----------------------------------------------");
    do{
        puts("There are several functions that you can use to help your calculation of linear algebra");
        printf("1.Find the Soltion of the Matrix\n2.Find The Inverse of the Matrix\n3.LU Factorization of the Matrix\n4.Calculate the Determinant of the Matrix\n5.Matrix Multiplication",
        "\n6.Scalr operation on Matrix\n");
        puts("Please select the functions that you want to use(q/Q to quit the program):");
        while(scanf("%c",&q)){
            if(ch>='1'&&ch<='6')
                selection(ch-'0');
            else if(ch=='q'||ch=='Q'){
                break;
            }
            printf("Error!Please enter a valid character!\n");
            puts("Please select the functions that you want to use(q/Q to quit the program):");
        }
    }while(ch!='q'||ch!='Q');
}

void selection(int op){
    switch(op){
        case 1:FindSolutionDisplay();break;
        case 2:FindInverseDisplay();break;
        case 3:LUFactorizationDisplay();break;
        case 4:DeterminantDisplay();break;
        case 5:MatrixMultiplicationDisplay();break;
        case 6:break;
    }
}
/*Function Display*/
void FindSolutionDisplay(){
    puts("Please enter the matrix that you want to find solutions");
    matrix *mat=ReadMatrix();
    FindSolution(*mat);
    ReleaseMatrix(mat);
}

void FindInverseDisplay(){
    puts("Please enter the matrix that you want to find the inverse");
    matrix *mat=ReadMatrix();
    matrix *inver=FindInverse(*mat);
    PrintMatrix(*inver);
    ReleaseMatrix(inver);
    ReadMatrix(mat);
}
void LUFactorizationDisplay(){
    puts("Please enter the matrix that you want to do the LU factorization");
    matrix *mat=ReadMatrix();
    matrix *L=LUFactorization(mat);
    PrintMatrix(*L);
    PrintMatrix(*mat);
    ReleaseMatrix(L);
    ReleaseMatrix(mat);
}
void DeterminantDisplay(){
    puts("Please enter the matrix that you want to find the inverse");
    matrix *mat=ReadMatrix();
    database data=Determinant(*mat);
    if(data.deno==0)
        puts("Error!The matrix is not a square matrix!");
    else{
        printf("The determinant of the matrix is");
        print_row(data);
        puts("");
    }
    ReleaseMatrix(mat);
}
void MatrixMultiplicationDisplay(){
    char ch;
    puts("Please select the multiplication you want to do(only a character)");
    printf("a)Scalar Product\nb)Matrix Multiplication\n");
    scanf("%c",&ch);
    puts("Please enter the first matrix");
    matrix *mat1=ReadMatrix();
    puts("Please enter the second matrix");
    matrix *mat2=ReadMatrix();
    matrix *result;
    switch(ch){
        case 'a':result=MatrixMultiplicationScalarProduct(mat1,mat2);break;
        case 'b':result=MatrixMultiplication(mat1,mat2);break;
    }
    PrintMatrix(*result);
    ReleaseMatrix(result);
}
/*------------------------------------------------------------------------*/