//�����м����temp�����largest�ıȽϼ���ֵ����Ԥ�ȸ�temp��ֵ����Ч�ؼ���if������� 
#include<stdio.h>

int main(void){
	int i1, i2, i3, sum, average, product, smallest, largest, temp1, temp2;
	printf("Enter three different integers:");
	scanf("%d%d%d",&i1,&i2,&i3);
	sum=i1+i2+i3;
	average=sum/3;
	product=i1*i2*i3;
	temp1=i1;
	temp2=i1;
	if(temp1<=i2){
		temp1=i2;
	}//end if
	if(temp1<=i3){
		temp1=i3;
	}//end if
	if(temp2>=i2){
		temp2=i2;
	}
	if(temp2>=i3){
		temp2=i3;
	}//end if
	largest=temp1;
	smallest=temp2;
	printf("Sum is %d\nAverage is %d\nProduct is %d\nSmallest is %d\nLargest is %d",sum,average,product,smallest,largest);
	
}//end main

