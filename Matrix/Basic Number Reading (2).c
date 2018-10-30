#include <stdio.h>

unsigned long long basicNumberReading(int base);

int main() {
  int caseNum = 0, base = 0;
  scanf("%d %d", &caseNum, &base);
  for (int caseIndex = 0; caseIndex < caseNum; ++caseIndex) {
    printf("%llu\n", basicNumberReading(base));
  }   
  return 0;
} 

unsigned long long basicNumberReading(int base){
	unsigned long long total=0;
	char ch=getchar();
	total=ch!=10?ch-48:0;	
	while((ch=getchar())!=10)
		total=total*base+(ch-48);
	return total;
}