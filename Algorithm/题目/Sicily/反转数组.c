#include<stdio.h>
#define SIZE 3 
void displaymatrix(int matrix[SIZE][SIZE],int matrixRowSize,int matrixColSizes);
void rotate(int matrix[][SIZE],int matrixRowSize,int *matrixColSizes);
int main(){
	int matrix[SIZE][SIZE]={{1,2,3},{4,5,6},{7,8,9}};
	displaymatrix(matrix,SIZE,SIZE);
	int k=SIZE;
	rotate(matrix,SIZE,&k);
	displaymatrix(matrix,SIZE,SIZE);
	return 0;
}
void rotate(int matrix[][SIZE],int matrixRowSize,int *matrixColSizes){
	int temp=matrixRowSize/2,k,i,j,temp1,temp2,temp3;
	for(k=0;k<temp;k++){
		for(j=0;j<=3;j++){
			switch(j){
				case 0:temp1=matrix[k][*matrixColSizes-1-k];matrix[k][*matrixColSizes-1-k]=matrix[k][k];temp2=temp1;break;
				case 1:temp1=matrix[matrixRowSize-k-1][*matrixColSizes-1-k];matrix[matrixRowSize-k-1][*matrixColSizes-1-k]=temp2;temp2=temp1;break;
				case 2:temp1=matrix[matrixRowSize-k-1][k];matrix[matrixRowSize-1-k][k]=temp2;temp2=temp1;break;
				case 3:matrix[k][k]=temp2;break;
			}
		}
		for(i=k+1;i<=*matrixColSizes-1-k-1;i++){
			for(j=0;j<=3;j++){
				switch(j){
					case 0:temp1=matrix[i][*matrixColSizes-1-k];matrix[i][*matrixColSizes-1-k]=matrix[k][i];temp2=temp1;break;
					case 1:temp1=matrix[matrixRowSize-k-1][*matrixColSizes-1-i];matrix[matrixRowSize-k-1][*matrixColSizes-1-i]=temp2;temp2=temp1;break;
					case 2:temp1=matrix[matrixRowSize-i-1][k];matrix[matrixRowSize-i-1][k]=temp2;temp2=temp1;break;
					case 3:matrix[k][i]=temp2;break;
				}
			}
		} 
	}
}

void displaymatrix(int matrix[][SIZE],int matrixRowSize,int matrixColSizes){
	int i,j;
	for(i=0;i<matrixRowSize;i++){
		for(j=0;j<matrixColSizes;j++)
			printf("%d ",matrix[i][j]);
		puts("");
	}
	puts("");
}
