#include<stdio.h>

int main(void){
    int num,i;
    double x_min,x_max,y_min,y_max;
    scanf("%d",&num);
    double x[num*4+1],y[num*4+1];
    scanf("%lf%lf",&x[1],&y[1]);
    x_min=x_max=x[1];
    y_min=y_max=y[1];
    for(i=2;i<=num*4;i++){
        scanf("%lf%lf",&x[i],&y[i]);
        if(x[i]<x_min){
            x_min=x[i];
        }
        if(x[i]>x_max){
            x_max=x[i];
        }
        if(y[i]>y_max)
            y_max=y[i];
        if(y[i]<y_min)
            y_min=y[i];
    }
    printf("%.2f\n",(x_max-x_min)*(y_max-y_min));    
    return 0;
}