// Time Complexity 
// Best case     - O(nlogn)
// Average case  - O(n^2)
// Worst case    - O(n^2)

// Space         - O(logn) to O(n)


#include<stdio.h>

// Function to perform quicksort
void f(int a[], int low, int high) {
    int pivot, i, j, t;
    if (low < high) {
        pivot = a[low];  // Choose the first element as the pivot
        i = low + 1;
        j = high;
        
        // Partition the array
        while (1) {
            while (a[i] < pivot && i <= high) {
                i++;
            }
            while (a[j] > pivot && j >= low) {
                j--;
            }
            if (i < j) {
                // Swap elements
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            } 
            else 
            {
                break;
            }
        }

        // Place the pivot in the correct position
        a[low] = a[j];
        a[j] = pivot;

        // Recursively sort the left and right subarrays
        f(a, low, j - 1);
        f(a, j + 1, high);
    }
}

int main() {
    int a[5], n, i, low, high;

    // Input array size
    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    low = 0;
    high = n - 1;

    // Call quicksort function
    f(a, low, high);

    // Print the sorted array
    printf("Array after quick sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
