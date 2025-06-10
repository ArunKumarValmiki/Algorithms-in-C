// Time complexity   - O(m * n)
// Spcae complexity  - O(m * n)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Directions: up, down, left, right
int dirX[] = {-1, 1, 0, 0};
int dirY[] = {0, 0, -1, 1};

// Get max of 2 integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// DFS with memoization
int dfs(int** matrix, int i, int j, int** dp, int rows, int cols, int prev) {
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        return 0;
    if (matrix[i][j] <= prev)
        return 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    int maxPath = 0;
    for (int d = 0; d < 4; d++) {
        int x = i + dirX[d];
        int y = j + dirY[d];
        int path = dfs(matrix, x, y, dp, rows, cols, matrix[i][j]);
        maxPath = max(maxPath, path);
    }

    dp[i][j] = 1 + maxPath;
    return dp[i][j];
}

// Main function to compute the longest increasing path
int longestIncreasingPath(int** matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) return 0;

    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)calloc(cols, sizeof(int));
    }

    int maxLen = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int len = dfs(matrix, i, j, dp, rows, cols, -2147483648); // INT_MIN
            maxLen = max(maxLen, len);
        }
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);

    return maxLen;
}

int main() {
    int matrixData[3][3] = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    int rows = 3, cols = 3;

    // Convert static 2D array to dynamic for compatibility
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = matrixData[i][j];
        }
    }

    int result = longestIncreasingPath(matrix, rows, cols);
    printf("Longest Increasing Path: %d\n", result);

    // Free matrix memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
