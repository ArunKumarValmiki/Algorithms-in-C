#include <stdio.h>

void findMinCoins(int coins[], int n, int amount) {
    int count = 0;
    printf("Coins used to make change for %d:\n", amount);
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
            count++;
        }
    }
    if (amount != 0)
        printf("\nRemaining amount: %d (cannot be represented with given denominations)", amount);
    printf("\nMinimum number of coins required: %d\n", count);
}

int main() {
    // Example coin denominations (Indian currency)
    int coins[] = {10, 5, 2, 1};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount;

    printf("Enter the amount: ");
    scanf("%d", &amount);

    findMinCoins(coins, n, amount);
    return 0;
}
