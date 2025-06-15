// Top Down DP 
// Time Complexity   - O(total * n)
// Spcae Complexity  - O(total + recursion) 

// Bottom Up DP 
// Time Complexity   - O(total * n)
// Space Complexity  - O(total)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// ----------- Top-Down DP with Memoization -----------
int minCoinTopDown(int total, int coins[], int n, int memo[]) {
    if (total == 0) return 0;
    if (memo[total] != -1) return memo[total];

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (coins[i] > total) continue;

        int val = minCoinTopDown(total - coins[i], coins, n, memo);
        if (val != INT_MAX && val + 1 < min)
            min = val + 1;
    }

    memo[total] = min;
    return memo[total];
}

// ----------- Bottom-Up DP with Coin Trace -----------
int minCoinBottomUp(int total, int coins[], int n) {
    int* T = (int*)malloc((total + 1) * sizeof(int));
    int* R = (int*)malloc((total + 1) * sizeof(int));

    for (int i = 0; i <= total; i++) {
        T[i] = INT_MAX - 1;
        R[i] = -1;
    }
    T[0] = 0;

    for (int j = 0; j < n; j++) {
        for (int i = coins[j]; i <= total; i++) {
            if (T[i - coins[j]] + 1 < T[i]) {
                T[i] = T[i - coins[j]] + 1;
                R[i] = j;
            }
        }
    }

    // Print coin combination
    if (R[total] == -1) {
        printf("No solution is possible.\n");
    } else {
        printf("Coins used to form total: ");
        int start = total;
        while (start != 0) {
            int j = R[start];
            printf("%d ", coins[j]);
            start -= coins[j];
        }
        printf("\n");
    }

    int result = T[total];
    free(T);
    free(R);
    return result;
}


int main() {
    int coins[] = {7, 3, 2, 6};
    int total = 13;
    int n = sizeof(coins) / sizeof(coins[0]);

    int* memo = (int*)malloc((total + 1) * sizeof(int));
    for (int i = 0; i <= total; i++) memo[i] = -1;

    int topDownResult = minCoinTopDown(total, coins, n, memo);
    int bottomUpResult = minCoinBottomUp(total, coins, n);

    printf("Bottom up and top down result: %d %d\n", bottomUpResult, topDownResult);

    free(memo);
    return 0;
}
