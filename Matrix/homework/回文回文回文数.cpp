#include <iostream>

using namespace std;
int digit[100]={0};
bool isPalindrome(int num);

int main() {
	int n,num,i,count = 0;
	for(i=11;i<1000;i++){
		if(isPalindrome(i)&&isPalindrome(i*i)&&isPalindrome(i*i*i))
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}

bool isPalindrome(int num){
	bool Palindrome=true;
	int count=0;
	while(num){
			digit[count++]=num%10;
			num /= 10;
	}
	for(int k=0;k<count/2;++k) {
		if (digit[k] != digit[count-1-k]) {
			Palindrome = false;
			break;
		}
	}
	return Palindrome;
}
