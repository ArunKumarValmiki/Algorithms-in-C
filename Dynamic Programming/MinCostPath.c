#include <stdio.h>
#include <limits.h>

int min(int a, int b, int c) {
    int temp = a < b ? a : b;
    return (temp < c ? temp : c);
}

// Dynamic Programming approach
int minCostDP(int cost[100][100], int m, int n) {
    int temp[100][100];

    temp[0][0] = cost[0][0];

    // Initialize first row
    for (int i = 1; i <= n; i++)
        temp[0][i] = temp[0][i - 1] + cost[0][i];

    // Initialize first column
    for (int i = 1; i <= m; i++)
        temp[i][0] = temp[i - 1][0] + cost[i][0];

    // Fill the rest of the table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            temp[i][j] = cost[i][j] + min(temp[i - 1][j - 1], temp[i - 1][j], temp[i][j - 1]);
        }
    }

    return temp[m][n];
}

// Recursive approach
int minCostRec(int cost[100][100], int m, int n, int x, int y) {
    if (x > m || y > n)
        return INT_MAX;

    if (x == m && y == n)
        return cost[x][y];

    int t1 = minCostRec(cost, m, n, x + 1, y);
    int t2 = minCostRec(cost, m, n, x + 1, y + 1);
    int t3 = minCostRec(cost, m, n, x, y + 1);

    return cost[x][y] + min(t1, t2, t3);
}

int main() {
    int cost[100][100] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3},
        {6, 2, 9}
    };

    int m = 3, n = 2;

    int resultDP = minCostDP(cost, m, n);
    int resultRec = minCostRec(cost, m, n, 0, 0);

    printf("Minimum cost using DP: %d\n", resultDP);
    printf("Minimum cost using Recursion: %d\n", resultRec);

    return 0;
}
