#include <cstdio>
int f(int n){if(n == 0)return 1;return n*f(n-1);}int main(){printf("%i", f(5));}