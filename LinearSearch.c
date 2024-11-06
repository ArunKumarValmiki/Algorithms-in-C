// Time Complexity
// Best case     - O(1)
// Average case  - O(n)
// Worst case    - O(n)

// Space : O(1)


# include<stdio.h>

int linearSearch(int arr[], int n, int key) {
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    
    return -1;
}


int main() {
    
    int arr[100],n,key;
    
    printf("Enter the size of array: ");
    scanf("%d",&n);
    
    printf("Enter the elements of Array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    
    printf("\nEnter the element to search: ");
    scanf("%d",&key);
    
    int index = linearSearch(arr,n,key);
    
    if (index != -1) {
        printf("Element found at index %d",index);
    }
    else {
        printf("Element not found");
    }
    
}



