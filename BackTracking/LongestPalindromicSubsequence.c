// TIme complexity  - O(n^2)
// Space complexity - O(n^2) 

#include <stdio.h>
#include <string.h>

// Utility to get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of longest palindromic subsequence
int longestPalindromicSubsequence(char* str) {
    int n = strlen(str);
    int dp[n][n];

    // All substrings of length 1 are palindromes of length 1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Fill the table
    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i < n - cl + 1; i++) {
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }

    return dp[0][n - 1];  // Length of LPS is in dp[0][n-1]
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);

    int lpsLength = longestPalindromicSubsequence(str);
    printf("Length of Longest Palindromic Subsequence: %d\n", lpsLength);

    return 0;
}
