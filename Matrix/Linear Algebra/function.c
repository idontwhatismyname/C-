#include"header.h"

database Determinant(const matrix mat1){
    if(mat1.row!=mat1.col){
        printf("Wrong!It is not a square Matrix");
        return (database){1,0};//if there don't exit the determinant return 1/0 to indicate nan
    }
    else{
		int i,j;
        database mul={1,1};
        matrix *mat2=InitializeMatrix(mat1.row,mat1.col);
		for(i=1;i<=mat1.row;i++)
			for(j=1;j<=mat1.col;j++)
				mat2->data[i][j]=mat1.data[i][j];
		bool negative=RowReduceToEchelonForm(mat2);
        for(i=1;i<=mat1.row;i++)
            mul=Multiply(mul,mat2->data[i][i]);
        if(negative)
			mul.numer*=(-1);
        ReleaseMatrix(mat2);
		return mul;
    }
}

void SolutionSet(matrix mat){//Input a row reduced matrix and print out the solution set
	int i,j=1;
	bool col[mat.col+1];
	database free[mat.row+1][mat.col+1];
	for(i=1;i<=mat.col;i++){
		col[i]=false;
	}
	for(i=1;i<=mat.row;i++){
		for(j;j<=mat.col;j++){
			if(mat.data[i][j].numer!=0){
				col[j]=true;
				j++;
				break;
			}
		}
	}
	for(i=1;i<=mat.col-1;i++){
		if(col[i]==false){
			for(j=1;j<=mat.row;j++)
				free[j][i]=(i==j?(database){1,1}:Multiply((database){-1,1},mat.data[j][i]));
		}
	}
	for(i=1;i<=mat.row;i++){
		for(j=1;j<=mat.col-1;j++){
			if(col[j]==false)
				print_row(free[i][j]);
		}
		print_row(mat.data[i][mat.col]);
		puts("");
	}
}//still needs to improve the format.

void FindSolution(matrix mat){
	RowReduceToRowReduceEchelonForm(&mat);
	if(mat.data[mat.row][mat.col].numer!=0)
		puts("No solution");
	else{
		SolutionSet(mat);
	}
	return ;
}


matrix *FindInverse(matrix mat){
	database deter=Determinant(mat);
	if(deter.numer==0){
		return NULL;
	}
	matrix *inver=InitializeMatrix(mat.row,mat.col*2);
	int i,j;
	for(i=1;i<=mat.row;i++){
		for(j=1;j<=mat.col;j++){
			inver->data[i][j]=mat.data[i][j];
		}
		for(j;j<=2*mat.col;j++){
			if(i==j-mat.col)
				inver->data[i][j].numer=1;
			else
				inver->data[i][j].numer=0;
		}
	}
	RowReduceToRowReduceEchelonForm(inver);
	PrintMatrix(*inver);
	matrix *inverse=InitializeMatrix(mat.row,mat.col);
	for(i=1;i<=mat.row;i++){
		for(j=1;j<=mat.col;j++){
			inverse->data[i][j]=inver->data[i][mat.col+j];
		}
	}
	ReleaseMatrix(inver);
	return inverse;
}//need to be Release

matrix *LUFactorization(matrix *mat){//only supported the matrix which can row reduce to echelon while only using row replacement
	matrix *L=InitializeMatrix(mat->row,mat->row);
	database data={1,1},multiple;
	int i,j,k,pivot=0,q;
	for(i=1;i<=mat->row;i++){
		L->data[i][i].numer=1;
		for(k=pivot+1;k<=mat->col;k++)
			if(mat->data[i][k].numer!=0){
				pivot=k;
				data=mat->data[i][k];
				break;
			}
		for(q=i+1;q<=mat->row&&k<=mat->col;q++){
			L->data[q][i]=Divide(mat->data[q][k],data);
			multiple=Multiply((database){-1,1},Divide(mat->data[q][k],data));
			Replacement(mat->data[i],mat->data[q],mat->col,multiple);
		}
	}
	return L;	
}//return L back where mat become U

matrix *MatrixMultiplicationScalarProduct(matrix *mat1,matrix *mat2){
	int i,j;
	for(i=1;i<=mat1->row;i++){
		for(j=1;j<=mat1->col;j++){
			mat1->data[i][j]=Multiply(mat1->data[i][j],mat2->data[i][j]);
		}
	}
	ReleaseMatrix(mat2);
	return mat1;
}

matrix *MatrixMultiplication(matrix *mat1,matrix *mat2){
	int i,j,k,q;
	database sum={0,1};
	matrix *NewMat=InitializeMatrix(mat1->row,mat2->col);
	for(i=1;i<=mat1->row;i++){
		for(j=1;j<=mat2->col;j++){
			sum=(database){0,1};
			for(k=1;k<=mat1->col;k++){
				sum=Add(sum,Multiply(mat1->data[i][k],mat2->data[k][j]));
			}
			NewMat->data[i][j]=sum;
		}
	}
	ReleaseMatrix(mat2);
	ReleaseMatrix(mat1);
	return NewMat;
}

void ScalarOperation(char q,matrix *mat,database scalar){
	int i,j;
	char operation[4]={'+','-','*','/'};
	database (*op)(database,database);
	database (*opera[4])(database,database)= { Add , Subtract , Multiply , Divide };
	for(i=0;i<=3;i++){
		if(q==operation[i]){
			op=opera[i];
			break;
		}
	}
	for(i=1;i<=mat->row;i++){
		for(j=1;j<=mat->col;j++){
			mat->data[i][j]=op(mat->data[i][j],scalar);
		}
	}
}//左右除法要做区分 