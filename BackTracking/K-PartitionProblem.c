#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

// Function to check if partition is possible
bool isKPartitionPossible(int arr[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // If total sum is not divisible by k, partition is not possible
    if (sum % k != 0)
        return false;

    int target = sum / k;
    int subsetSum[k];
    bool taken[n];

    for (int i = 0; i < k; i++)
        subsetSum[i] = 0;
    for (int i = 0; i < n; i++)
        taken[i] = false;

    // Place last element in the first subset
    subsetSum[0] = arr[n - 1];
    taken[n - 1] = true;

    // Start recursive backtracking from index 0 and 1 subset filled
    return canPartition(arr, taken, subsetSum, target, k, n, 0, n - 1);
}

// Recursive helper
bool canPartition(int arr[], bool taken[], int subsetSum[], int target,
                  int k, int n, int curIdx, int limitIdx) {
    if (subsetSum[curIdx] == target) {
        if (curIdx == k - 2)
            return true;

        return canPartition(arr, taken, subsetSum, target, k, n, curIdx + 1, n - 1);
    }

    for (int i = limitIdx; i >= 0; i--) {
        if (taken[i])
            continue;

        int tmp = subsetSum[curIdx] + arr[i];

        if (tmp <= target) {
            taken[i] = true;
            subsetSum[curIdx] += arr[i];
            bool next = canPartition(arr, taken, subsetSum, target, k, n, curIdx, i - 1);
            taken[i] = false;
            subsetSum[curIdx] -= arr[i];
            if (next)
                return true;
        }
    }

    return false;
}

int main() {
    int arr[MAX], n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value of k (number of subsets): ");
    scanf("%d", &k);

    if (isKPartitionPossible(arr, n, k))
        printf("Yes, the array can be partitioned into %d subsets with equal sum.\n", k);
    else
        printf("No, such a partition is not possible.\n");

    return 0;
}
