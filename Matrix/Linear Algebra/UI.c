/**
 *    author:  ouyanghaolan
 *    created: 07.01.2019   
**/
#include"header.h"

void ui(){
    char ch;
    puts("Welcome to my Linear Algebra Package!");
    puts("-----------------------------------------------------------------------------------------");
    puts("-----------------------------------------------------------------------------------------");
	puts("There are several functions that you can use to help your calculation of linear algebra\n");
	printf("\t1.Find the Soltion of the Matrix\n\t2.Find The Inverse of the Matrix\n\t3.LU Factorization of the Matrix\n"    
	"\t4.Calculate the Determinant of the Matrix\n\t5.Matrix Multiplication"
    "\n\t6.Scalr operation on Matrix\n\t7.QR Factorization of the Matrix\n\n");
    printf("Please select the functions that you want to use(q/Q to quit the program):");
    while(scanf("%c",&ch)!=EOF){
        getchar();
		if(ch>='1'&&ch<='7')
            selection(ch-'0');
        else if(ch=='q'||ch=='Q'){
            break;
        }
        else 
            printf("Error!Please enter a valid character!\n");
		puts("\n-----------------------------------------------------------------------------------------");
		printf("Functions:\n\t1.Find the Soltion of the Matrix\n\t2.Find The Inverse of the Matrix\n\t3.LU Factorization of the Matrix\n"    
		"\t4.Calculate the Determinant of the Matrix\n\t5.Matrix Multiplication"
    	"\n\t6.Scalr operation on Matrix\n\t7.QR Factorization of the Matrix\n\n");
    	printf("Please select the functions that you want to use(q/Q to quit the program):");
    }
    puts("Thank you for using the application!\nHave a nice day!");
}

void selection(char op){
    switch(op){
        case 1:FindSolutionDisplay();break;
        case 2:FindInverseDisplay();break;
        case 3:LUFactorizationDisplay();break;
        case 4:DeterminantDisplay();break;
        case 5:MatrixMultiplicationDisplay();break;
        case 6:ScalarOperationDisplay();break;
        case 7:QRFactorizationDisplay();break;
    }
}
/*Function Display*/
void FindSolutionDisplay(){
	puts("Find the solution of Ax=b");
	puts("\nEnter the matrix A:");
	matrix *matA=ReadMatrix();
	puts("\nEnter vector b:");
	matrix *matb=ReadMatrix();
	puts("");
	FindSolution(*matA,*matb);
    ReleaseMatrix(matA);
    ReleaseMatrix(matb);
}

void FindInverseDisplay(){
	printf("\nEnter the matrix that you want to find the inverse:\n");
    matrix *mat=ReadMatrix();
    puts("");
	matrix *inver=FindInverse(*mat);
    if(inver!=NULL){
		puts("");
		PrintMatrix(*inver);
    	puts("");
    	ReleaseMatrix(inver);
    	ReleaseMatrix(mat);
	}
	else
		puts("Inverse Not Found!");
}

void LUFactorizationDisplay(){
    puts("\nEnter the matrix that you want to do the LU factorization:");
    matrix *mat=ReadMatrix();
    matrix *L=LUFactorization(mat);
    puts("");
    PrintMatrix(*L);
    puts("");
    PrintMatrix(*mat);
    ReleaseMatrix(L);
    ReleaseMatrix(mat);
}

void DeterminantDisplay(){
    puts("\nEnter the matrix that you want to calculate the determinant:");
    matrix *mat=ReadMatrix();
    database data=Determinant(*mat);
    if(data.deno==0)
        puts("\nError!The matrix is not a square matrix!");
    else{
        printf("\nThe determinant of the matrix is ");
        print(data);
        puts("");
    }
    ReleaseMatrix(mat);
}

void MatrixMultiplicationDisplay(){
    char ch;
    puts("\nSelect the multiplication you want to do(only a character):");
    printf("a)Scalar Product\nb)Matrix Multiplication:");
    ch=getchar();
    puts("\nEnter the first matrix:");
    matrix *mat1=ReadMatrix();
    puts("\nEnter the second matrix:");
    matrix *mat2=ReadMatrix();
    matrix *result;
    switch(ch){
        case 'a':result=MatrixMultiplicationScalarProduct(mat1,mat2);break;
        case 'b':result=MatrixMultiplication(mat1,mat2);break;
    }
    puts("");
    PrintMatrix(*result);
    puts("");
    ReleaseMatrix(result);
}
void ScalarOperationDisplay(){
	printf("\nEnter your calculation formular:\n");
	int index=0,curr,row=1,col=1,i,j;
	bool colStatus=true,operand=true;//true indicate left false indicate right
	database scalar;
	matrix *mat;
	char str[MAXStr],op;
	scanf("%s",str);
	getchar();
	for(;str[index]==' ';index++);
	if(str[index]!='['){
		operand=false;
		scalar=read(str,&index);
		for(;str[index]==' ';index++);
		op=str[index];
		curr=index++;
		while(str[++curr]!=']'){
			if(str[curr]==';'){
				colStatus=false;
				row++;
			}
			else if(str[curr]==','&&colStatus)
				col++;
		}
		mat=InitializeMatrix(row,col);
		for(i=1;i<=row;i++){
        	for(j=1;j<=col;j++)
            	mat->data[i][j]=read(str,&index);
    	}	
	}
	else{
		curr=index;
		while(str[++curr]!=']'){
			if(str[curr]==';'){
				colStatus=false;
				row++;
			}
			else if(str[curr]==','&&colStatus)
				col++;
		}
		mat=InitializeMatrix(row,col);
		for(i=1;i<=row;i++){
        	for(j=1;j<=col;j++)
            	mat->data[i][j]=read(str,&index);
    	}
    	for(;str[index]==' '||str[index]==']';index++);
    	op=str[index];
    	scalar=read(str,&index);
	}
	ScalarOperation(op,mat,scalar,operand);
	PrintMatrix(*mat);
    ReleaseMatrix(mat);
}

void QRFactorizationDisplay(){
    printf("\nPlease enter the matrix that you want to do the QR factorization:\n");
    matrix *mat=ReadMatrix();
    matrix *R=QRFactorization(mat);
    puts("");
    PrintMatrix(*mat);
    puts("");
    PrintMatrix(*R);
    ReleaseMatrix(R);
    ReleaseMatrix(mat);
}

/*------------------------------------------------------------------------*/