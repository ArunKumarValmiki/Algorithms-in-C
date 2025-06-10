// Time Complexity 
// Best Case      - O(m * n)
// Average Case   - O(m * n)
// Worst case     - O(m * n) 

// Spcae Complexity - O(m * n) 
// m - Length of string 1 
// n - Length of string 2 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void longestCommonSubstring(char *text1, char *text2) {
    int m = strlen(text1);
    int n = strlen(text2);

    int dp[m + 1][n + 1];
    int maxLength = 0;
    int endIndex = 0;

    // Initialize the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the DP table and track the longest common substring
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;  // Save end index of substring in text1
                }
            } else {
                dp[i][j] = 0;  // Reset on mismatch
            }
        }
    }

    // Print results
    printf("Length of Longest Common Substring: %d\n", maxLength);

    if (maxLength > 0) {
        char *lcs = (char *)malloc((maxLength + 1) * sizeof(char));
        strncpy(lcs, &text1[endIndex - maxLength + 1], maxLength);
        lcs[maxLength] = '\0';
        printf("Longest Common Substring: %s\n", lcs);
        free(lcs);
    } else {
        printf("No common substring found.\n");
    }
}

int main() {
    char text1[1000], text2[1000];

    printf("Enter first string: ");
    scanf("%s", text1);

    printf("Enter second string: ");
    scanf("%s", text2);

    longestCommonSubstring(text1, text2);
    return 0;
}
