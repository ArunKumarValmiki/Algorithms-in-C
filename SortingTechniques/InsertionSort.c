// Time Complexity 
// Best case     - O(n)
// Average case  - O(n^2)
// Worst case    - O(n^2)

// Space         - O(1)


#include<stdio.h>

int main() {
    int a[10], n, i, j, temp;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    /* Reading elements into an array */
    printf("Enter the elements of array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    /* Print array elements before sorting */
    printf("Elements before sorting an array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    /* Logic for Insertion Sort */
    for(i = 1; i < n; i++) {
        temp = a[i];
        for(j = i; j > 0 && temp < a[j - 1]; j--) {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }

    printf("\n");
    printf("Elements after sorting an array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
