// Time Complexity 
// Best Case      - O(m * n)
// Average Case   - O(m * n)
// Worst case     - O(m * n) 

// Spcae Complexity - O(m * n) 
// m - Length of string 1 
// n - Length of strign 2 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to compute and print LCS
void printLCS(char *text1, char *text2) {
    int m = strlen(text1);
    int n = strlen(text2);
    
    int dp[m + 1][n + 1];

    // Fill the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Length of LCS
    int index = dp[m][n];
    printf("Length of LCS: %d\n", index);

    // Allocate memory for LCS string
    char *lcs = (char *)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';

    // Backtrack to find LCS
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs[index - 1] = text1[i - 1];
            i--; j--; index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("LCS string: %s\n", lcs);
    free(lcs);
}

int main() {
    char text1[1000], text2[1000];

    printf("Enter first string: ");
    scanf("%s", text1);

    printf("Enter second string: ");
    scanf("%s", text2);

    printLCS(text1, text2);

    return 0;
}
