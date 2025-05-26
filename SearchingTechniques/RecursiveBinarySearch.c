// Time Complexity 
// Best case    - O(1) 
// Average case - O(log n)
// Worst case   - O(log n)

// Space complexity - O(log n) 


#include <stdio.h>

int recursiveBinarySearch(int arr[], int left, int right, int key) {
    if (left == right) {
        if (arr[left] == key)
            return left;
        else
            return -1;
    } else {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return recursiveBinarySearch(arr, left, mid - 1, key);
        else
            return recursiveBinarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

int main() {
    int n, arr[10];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements of array in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int pos = recursiveBinarySearch(arr, 0, size - 1, key);

    if (pos != -1)
        printf("Element is found at index %d\n", pos);
    else
        printf("Element is not found\n");

    return 0;
}
