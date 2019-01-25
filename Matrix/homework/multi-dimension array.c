#include<stdio.h>

void print_mat(int* arr, int n, int m);
void print_three_dimension_tensor(int* arr, int n, int m, int o);
void print_four_dimension_tensor(int* arr, int n, int m, int o, int p);

int main(void) {

	int arr_1[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int n = 3, m = 4;
	print_mat(arr_1, n, m);

	int arr_2[24] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
	int o = 4;
	n = 2;
	m = 3;

	print_three_dimension_tensor(arr_2, n, m, o);

	int arr_3[120];
	for (n = 0; n < 120; n++) {
		arr_3[n] = n + 1;
	}
	int p = 5;
	n = 2;
	m = 3;
	o = 4;
	p = 5;
	print_four_dimension_tensor(arr_3, n, m, o, p);
	return 0;
}
void print_mat(int* arr, int n, int m){
    printf("[\n");
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) printf("%3d",*(arr+i*m+j));
        puts("");
    }
    printf("]\n");
}
void print_three_dimension_tensor(int* arr, int n, int m, int o){
    printf("[\n");
    int i,j,k;
    for(i=0;i<n;i++){
        printf("  [\n");
        for(j=0;j<m;j++){
            for(k=0;k<o;k++) printf("%5d",*(arr+i*m*o+j*o+k));
            puts("");
        }
        printf("  ]");
        if(i!=n-1)
            printf(",");
        puts("");
    }
    printf("]\n");
}
void print_four_dimension_tensor(int* arr, int n, int m, int o, int p){
    printf("[\n");
    int i,j,k,l;
    for(i=0;i<n;i++){
        printf("  [\n");
        for(j=0;j<m;j++){
            printf("    [\n");
            for(k=0;k<o;k++){
                for(l=0;l<p;l++) printf("%7d",*(arr+i*m*o*p+j*o*p+k*p+l));
                puts("");
            }
            printf("    ]");
            if(j!=m-1)
                printf(",");
            puts("");
        }
        printf("  ]");
        if(i!=n-1)
            printf(",");
        puts("");
    }
    printf("]\n");
}