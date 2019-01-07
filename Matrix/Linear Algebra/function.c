/**
 *    author:  ouyanghaolan
 *    created: 07.01.2019   
**/
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
	bool col[mat.col+1],frevar=false;
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
	printf("The solution set is :");
	for(j=1;j<=mat.col-1;j++){
		if(col[j]==false){
			frevar=true;
			printf(" X%d * [",j);
			for(i=1;i<=mat.row;i++){
				print(free[i][j]);
				printf("%c",i==mat.row?']':';');
			}
			printf(" + ");
		}
	}
	printf("[");
	for(i=1;i<=mat.row;i++){
		print(mat.data[i][mat.col]);
		printf("%c",i==mat.row?']':';');
	}
	if(frevar){
		printf(" ( ");
		for(j=1;j<=mat.col-1;j++){
			if(col[j]==false)
				printf("X%d ",j);
		}
		printf("is free variable )");
	}
	puts("");
	
}//still needs to improve the format.

void FindSolution(matrix mata,matrix matb){
	bool status=true;
	int i,j;
	matrix *mat=InitializeMatrix(mata.row,mata.col+1);
	for(i=1;i<=mata.row;i++){
		for(j=1;j<=mata.col;j++)
			mat->data[i][j]=mata.data[i][j];
		mat->data[i][j]=matb.data[i][1];
	}
	RowReduceToRowReduceEchelonForm(mat);
	for(i=mata.row;i>=1;i--){
		if(mat->data[i][mat->col].numer!=0){
			status=false;
			for(j=1;j<=mat->col-1;j++)
				if(mat->data[i][j].numer!=0){
					status=true;
					break;
				}
			break;
		} 
	}
	if(status==false)
		puts("No solution!");
	else{
		SolutionSet(*mat);
	}
	return ;
}


matrix *FindInverse(matrix mat){
	if(mat.col!=mat.row)
		return NULL;
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

void ScalarOperation(char q,matrix *mat,database scalar,bool operand){
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
			if(operand)
				mat->data[i][j]=op(mat->data[i][j],scalar);
			else
				mat->data[i][j]=op(scalar,mat->data[i][j]);
		}
	}
}

database InnerProduct(const database vector1[],const database vector2[],const int num){
	database sum={0,1};
	int i;
	for(i=1;i<=num;i++){
		sum=Add(sum,Multiply(vector1[i],vector2[i]));
	}
	return sum;
}

matrix *QRFactorization(matrix *mat){
	int i,j,k;
	database row1[mat->row+1],row2[mat->row+1];
	database scalar;
	matrix *R=InitializeMatrix(mat->col,mat->col);
	for(i=1;i<=mat->col;i++)
		for(j=1;j<=mat->col;j++)
			R->data[i][j].numer=(i==j?1:0);
	for(i=2;i<=mat->col;i++){
		for(j=1;j<=i-1;j++){
			for(k=1;k<=mat->row;k++){
				row1[k]=mat->data[k][j];
				row2[k]=mat->data[k][i];
			}
			scalar=Divide(InnerProduct(row1,row2,mat->row),InnerProduct(row1,row1,mat->row));
			R->data[j][i]=scalar;
			for(k=1;k<=mat->row;k++){
				mat->data[k][i]=Subtract(mat->data[k][i],Multiply(scalar,mat->data[k][j]));
			}
		}
	}
	return R;
}