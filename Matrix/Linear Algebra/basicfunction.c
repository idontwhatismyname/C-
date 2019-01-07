/**
 *    author:  ouyanghaolan
 *    created: 07.01.2019   
**/
#include"header.h"

/*Functions for newly design database*/
database Add(database a1,database a2){
	database result;
	result.numer=a1.numer * a2.deno +a1.deno *a2.numer;
	result.deno=a1.deno * a2.deno;
	if(result.deno<0){
		CorrectData(&result);
	}
	if(result.numer!=0&&result.deno!=1)
		gcd(&result);
	return result;
}
database Subtract(database a1,database a2){
	/* result=a1-a2 */
	database result;
	result.numer=a1.numer * a2.deno - a2.numer * a1.deno;
	result.deno=a1.deno * a2.deno;
	if(result.deno<0){
		CorrectData(&result);
	}
	if(result.numer!=0&&result.deno!=1)
		gcd(&result);
	return result;
}
database Multiply(database a1,database a2){
	database result={0,1};
	if(a1.numer==0||a2.numer==0)
		result.numer=0; 
	else{
		result.numer=a1.numer * a2.numer;
		result.deno=a1.deno * a2.deno;
		if(result.deno<0){
			CorrectData(&result);
		}
		if(result.numer!=0&&result.deno!=1)
			gcd(&result);
	}
	return result;
}

database Divide(database a1,database a2){
	database result={0,1};//error needed to be added if a2=0
	if(a1.numer==0)
		result.numer=0; 
	else{
		result.numer=a1.numer * a2.deno;
		result.deno=a1.deno * a2.numer;
		if(result.deno<0){
			CorrectData(&result);
		}
		if(result.numer!=0&&result.deno!=1)
			gcd(&result);
		}
	return result;
}
void CorrectData(database *data){
	data->deno*=(-1);
	data->numer*=(-1);
}
void gcd_Row(database *row,int col){
    int n,n1,n2,i,temp;
    for(i=1;i<=col;i++){
        if(row[i].numer==0)
            continue;
        n1=abs(row[i].numer),n2=row[i].deno;
        if(n1<n2){
            temp=n1;
            n1=n2;
            n2=temp;
        }
        n=n1;
        while(n!=0){
            n=n1%n2;
            n1=n2;
            n2=n;
        }
        row[i].numer/=n1;
        row[i].deno/=n1;
    }
}
/* To simplify my database*/
void gcd(database*data1){
    int n,n1=abs(data1->numer),n2=data1->deno,temp;
    if(n1<n2){
        temp=n1;
        n1=n2;
        n2=temp;
    }
    n=n1;
    while(n!=0){
        n=n1%n2;
        n1=n2;
        n2=n;
    }
    data1->numer/=n1;
    data1->deno/=n1;
}
/*-------------------------------------------------------------*/
/*IO for my newly designed database*/
database read(char *str,int *index){
	bool negative=false;
	database data={0,1};
	for(;!(str[*index]>='0'&&str[*index]<='9');(*index)++)
		if(str[*index]=='-')
			negative=true;
	for(;str[*index]>='0'&&str[*index]<='9';data.numer=data.numer*10+str[*index]-'0',(*index)++);
    if(negative)
		data.numer*=-1; 
	if(str[*index]=='/'){
    	data.deno=0;
		for((*index)++;str[*index]>='0'&&str[*index]<='9';data.deno=data.deno*10+str[*index]-'0',(*index)++);
    }
	return data;
}
void print(database data){
	if(data.numer==0||data.deno==1)
		printf("%d",data.numer);
	else
		printf("%d/%d",data.numer,data.deno);
}
/*------------------------------------------------------------------------*/
/*row reduction of matrix*/
bool RowReduceToEchelonForm(matrix *mat){
    int i,j,counter=1,p;
    bool negative=false;
	bool status=false;
    database multiple;
    for(j=1;j<=mat->col&&counter<=mat->row;j++){
        status=false;
		if(mat->data[counter][j].numer==0){
            for(p=counter+1;p<=mat->row;p++){
                if(mat->data[p][j].numer!=0){
                    Interchange(mat->data[p],mat->data[counter],mat->col);
                    negative=!negative;
					status=true;
                    break;
                }
            }
        }
        else{
        	status=true;
        }
        if(status==false)
            continue;
        for(i=counter+1;i<=mat->row;i++){
            if(mat->data[i][j].numer==0)
                continue;
            multiple=Multiply((database){-1,1},Divide(mat->data[i][j],mat->data[counter][j]));
            if(multiple.deno<0){
            	CorrectData(&multiple);
            }
			Replacement(mat->data[counter],mat->data[i],mat->col,multiple);
        }
        counter++;
    }
	return negative;
}
void EchelonFormToReduceEchelonForm(matrix*mat){
    int i,j,k,pivot[mat->row+1];
	database multiple,scales;
	bool status=false;
	for(i=1;i<=mat->row;i++)
		pivot[i]=0; 
	pivot[1]=1;
	for(i=mat->row;i>=2;i--){
		status=false;
		for(j=1;j<=mat->col;j++){
			if(mat->data[i][j].numer!=0){
				status=true;
				break;
			}
		}
		if(status==false){
			continue;
		}
		else{
			pivot[i]=j;
			for(k=i-1;k>=1;k--){
				if(mat->data[k][j].numer==0)
                    continue;
            	multiple=Multiply((database){-1,1},Divide(mat->data[k][j],mat->data[i][j]));
                if(multiple.deno<0){
            		CorrectData(&multiple);
            	}
				Replacement(mat->data[i],mat->data[k],mat->col,multiple);
			}
		}
	}
	for(i=1;i<=mat->row;i++){
		if(pivot[i]!=0){
			scales=Divide((database){1,1},mat->data[i][pivot[i]]);
			Scaling(mat->data[i],scales,mat->col);
		}
	}
}
void RowReduceToRowReduceEchelonForm(matrix *mat){
	RowReduceToEchelonForm(mat);
    EchelonFormToReduceEchelonForm(mat);
    
}
/*--------------------------------------------------------------------------------------*/
/*Three elementary row operation*/
void Replacement(const database row1[],database row2[],const int col,const database multiple){
    //row2 is the row which will be replaced
    int i;
    database temp;
	for(i=1;i<=col;i++){
        temp=Multiply(row1[i],multiple);
		row2[i]=Add(temp,row2[i]);
    }
}
void Interchange(database *row1,database *row2,const int col){
    int i;
    database temp;
    for(i=1;i<=col;i++){
        temp=row1[i];
        row1[i]=row2[i];
        row2[i]=temp;
    }
}
void Scaling(database *row,const database scales,const int col){
    int i;
    for(i=1;i<=col;i++){
        row[i]=Multiply(row[i],scales);
    }
}
/*----------------------------------------------------------------*/
/*Matrix initialization release read print*/
matrix* ReadMatrix(){
    bool colStatus=true;
	int i,j,len,row=1,col=1,curr=-1,index=0;
    char str[MAXStr];
	scanf("%s",str);
	getchar();
	len=strlen(str);
	while(str[++curr]!=']'){
		if(str[curr]==';'){
			colStatus=false;
			row++;
		}
		else if(str[curr]==','&&colStatus)
			col++;
	}
	matrix *mat=InitializeMatrix(row,col);
	for(i=1;i<=row;i++){
        for(j=1;j<=col;j++)
            mat->data[i][j]=read(str,&index);
    }
    return mat;
}
void PrintMatrix(const matrix mat){
    int i,j;
    printf("[");
	for(i=1;i<=mat.row;i++){
		printf("\n\n%4c",' ');
		for(j=1;j<=mat.col;j++){
            if(mat.data[i][j].deno==1||mat.data[i][j].numer==0)
                printf("%4d%4c",mat.data[i][j].numer,' ');
            else
                printf("%3d/%-3d ",mat.data[i][j].numer,mat.data[i][j].deno);
        }
    }
    puts("\n]");
}
matrix *InitializeMatrix(int Row,int Col){
    database data={0,1};
	matrix *mat=(matrix*)malloc(sizeof(matrix));
    int i,j;
    mat->row=Row,mat->col=Col;
    mat->data=(database**)malloc((Row+1)*sizeof(database*));
    mat->data[0]=(database*)malloc(sizeof(database)*(Col+1));
    for(i=1;i<=Row;i++){
        mat->data[i]=(database*)malloc(sizeof(database)*(Col+1));
        for(j=1;j<=Col;j++)
            mat->data[i][j]=data;
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
/*------------------------------------------------------------------------*/