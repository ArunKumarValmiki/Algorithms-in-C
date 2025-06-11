// Time complexity  - O(n^2)
// Space complexity - O(n)

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestIncreasingSubsequence(int arr[], int n) {
    int dp[n];             // dp[i] stores length of LIS ending at i
    int prev[n];           // To reconstruct the actual LIS
    int i, j;

    // Initialize arrays
    for (i = 0; i < n; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }

    // Fill dp[] using bottom-up DP
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Find the index of the maximum value in dp[]
    int lisLength = 0, lisEnd = 0;
    for (i = 0; i < n; i++) {
        if (dp[i] > lisLength) {
            lisLength = dp[i];
            lisEnd = i;
        }
    }

    // Reconstruct LIS sequence
    int lis[lisLength];
    int k = lisLength - 1;
    while (lisEnd != -1) {
        lis[k--] = arr[lisEnd];
        lisEnd = prev[lisEnd];
    }

    // Print the LIS
    printf("Longest Increasing Subsequence: ");
    for (i = 0; i < lisLength; i++) {
        printf("%d ", lis[i]);
    }
    printf("\n");

    return lisLength;
}

int main() {
    int arr[1000], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int length = longestIncreasingSubsequence(arr, n);
    printf("Length of LIS: %d\n", length);

    return 0;
}
