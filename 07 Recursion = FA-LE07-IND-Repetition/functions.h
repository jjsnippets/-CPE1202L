
// gcc -o recursion.exe -g main.c power.c factorial.c fibonacci.c

void powerMenu();
void factorialMenu();
void fibonnaciMenu();

long int powerLoop(long int b, int e);
long int powerCall(long int b, int e);

int factorialLoop(int n);
int factorialCall(int n);

int fibonnaciLoop(int a);
int fibonnaciCall(int a);