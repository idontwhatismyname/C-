#include <stdio.h>

int main() {
  int t;
  unsigned int n;
  scanf("%d", &t);
  while (t--) {
    scanf("%u", &n);
    printf("%d\n", sumDigits(n));
  }
  return 0;
}

int sumDigits(int n){
  	int total;
  	total=n%10;
    while((n/=10)!=0)
		total+=n%10;
	return total;
}
