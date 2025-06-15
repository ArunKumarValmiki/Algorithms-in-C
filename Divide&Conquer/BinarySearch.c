// Time Complexity 
// Best case     - O(1)
// Average case  - O(logn)
// Worst case    - O(logn)


// Space         - O(1)


# include<stdio.h>

int binarySearch(int arr[], int n, int key) {
    
    int left = 0;
    int right = n - 1;
    
    
    while (left <= right) {
        
        int mid = (left + right) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        
        if (arr[mid] > key) {
            right = mid -1;
        }
        
        else {
            left = mid + 1;
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
    
    
    int index = binarySearch(arr,n,key);
    
    if (index != -1) {
        printf("Element found at index %d",index);
    }
    else {
        printf("Element not found");
    }
    
}
