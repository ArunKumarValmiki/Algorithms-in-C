// Time  -  O(n) 
// Space -  O(n) 

#include <stdio.h>

#define MAX 100
int fibMemo[MAX];

int fib(int n) {
    if (n <= 1)
        return n;
    if (fibMemo[n] != -1)
        return fibMemo[n];
    fibMemo[n] = fib(n - 1) + fib(n - 2);
    return fibMemo[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
        fibMemo[i] = -1;

    printf("Fibonacci(%d) = %d\n", n, fib(n));
    return 0;
}
