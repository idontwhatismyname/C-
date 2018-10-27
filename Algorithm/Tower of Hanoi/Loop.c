#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int main(void){
	bool d=true;
	int n,i;
	printf("Please enter the tower you need to move:");
	scanf("%d",&n);
	int a[64],b[64],c[64];
	int a1=n,b1=0,c1=0;
	if(n%2==0)
		d=false;
	int k=n;
	for(i=1;i<=n;i++)
		a[k--]=i;
	for(i=1;i<=pow(2,n)-1;i++){
		if(i%3==1){
			if(a[a1]<c[c1]||c1==0){
				c1++; 
				c[c1]=a[a1];
				a[a1]=0;
				a1--;
				printf("%d -> %d\n",1,d?3:2);
			}
			else{
				a1++;
				a[a1]=c[c1];;
				c[c1]=0;
				c1--;
				printf("%d -> %d\n",d?3:2,1);
			}
		}
		if(i%3==2){
			if(a[a1]<b[b1]||b1==0){
				b1++; 
				b[b1]=a[a1];
				a[a1]=0;
				a1--;
				printf("%d -> %d\n",1,d?2:3);
			}
			else{
				a1++;
				a[a1]=b[b1];;
				b[b1]=0;
				b1--;
				printf("%d -> %d\n",d?2:3,1);
			}
		}
		if(i%3==0){
			if(b1!=0&&(b[b1]<c[c1]||c1==0)){
				c1++; 
				c[c1]=b[b1];
				b[b1]=0;
				b1--;
				printf("%d -> %d\n",d?2:3,d?3:2);
			}
			else{
				b1++;
				b[b1]=c[c1];;
				c[c1]=0;
				c1--;
				printf("%d -> %d\n",d?3:2,d?2:3);
			}
		}
	}
	return 0;
}
