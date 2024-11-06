// Time Complexity 
// Best case     - O(n^2)
// Average case  - O(n^2)
// Worst case    - O(n^2)

// Space         - O(1)


#include<stdio.h>

int main() {
    int a[10], n, i, j, temp, min;

    printf("Enter the size of array: ");
    scanf("%d", &n);


    printf("Enter the elements of array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    
    printf("Elements before sorting an array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    /* Logic for Selection Sort */
    for(i = 0; i < n; i++) 
    {
        min = i; // Assume the current element is the minimum
        for(j = i + 1; j < n; j++) 
        {
            if(a[j] < a[min]) 
            {
                min = j; // Find the actual minimum element
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("\n");
    printf("Elements after sorting an array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
