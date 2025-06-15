// Time  - O(n) 
// Space - O(n) or O(1) 

#include <stdio.h>

int fib(int n) {
    if (n <= 1)
        return n;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fib(n));
    return 0;
}
