#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void read(int *memory,int index);
void write(int *memory,int index);
void load(int *memory,int index);
void store(int *memory,int index);
void add(int *memory,int index);
void subtract(int *memory,int index);
void divide(int *memory,int index);
void multiply(int *memory,int index);
int branch(int index);
int branchneg(int *memory,int index,int curr);
int branchzero(int *memory,int index,int curr);