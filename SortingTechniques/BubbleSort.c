// Time Complexity 
// Best case     - O(n)
// Average case  - O(n^2)
// Worst case    - O(n^2)

// Space         - O(1)


#include<stdio.h>

int main() {
    int a[5], n, i, j, temp, count = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter the elements of array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Bubble Sort Logic
    for(i = 0; i < n-1; i++) 
    {
        for(j = 0; j < n-i-1; j++) 
        {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                count = 1;  // Set count to indicate a swap occurred
            }
        }

        // Early exit if no swaps happened in the inner loop (array is already sorted)
        if(count == 1) {
            break;
        }
    }

    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
