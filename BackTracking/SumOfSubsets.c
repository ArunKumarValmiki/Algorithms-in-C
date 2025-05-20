#include <stdio.h>

void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void findSubsets(int arr[], int n, int target, int subset[], int index, int currentSum) {
    if (currentSum == target) {
        printSubset(subset, index);
        return;
    }
    if (n == 0) {
        return;
    }

    findSubsets(arr + 1, n - 1, target, subset, index, currentSum);

    subset[index] = arr[0];
    findSubsets(arr + 1, n - 1, target, subset, index + 1, currentSum + arr[0]);
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    int subset[n];
    printf("Subsets with sum equal to %d:\n", target);
    findSubsets(arr, n, target, subset, 0, 0);

    return 0;
}
