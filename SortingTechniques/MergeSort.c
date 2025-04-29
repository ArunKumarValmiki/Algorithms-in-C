// Time Complexity 
// Best case     - O(nlogn)
// Average case  - O(nlogn)
// Worst case    - O(nlogn)


// Space         - O(n)


#include<stdio.h>

void merge(int a[], int first, int mid, int last)
{
    int i, j , k, t[20];
    i = first;
    j = mid+1;
    k = first;
    
    while(i <= mid && j <= last)
    {
        if(a[i] >= a[j])
        {
            t[k++] = a[j++];
        }
        else
        {
            t[k++] = a[i++];
        }
    }
    
    while(i <= mid)
    {
        t[k++] = a[i++];
    }
    
    while(j <= last)
    {
        t[k++]=a[j++];
    }
    
    for(i = first; i <= last; i++)
    { 
        a[i]=t[i];
    }
}


void mergesort(int a[], int first, int last)
{
    
    if(first != last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid);
        mergesort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}


int main()
{
    int a[20], n, first, last;
    
    printf("Enter the size of array: ");
    scanf("%d",&n);
    
    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    first = 0;
    last = n-1;
    
    mergesort(a, first, last);
    printf("Array after the merge sort: ");
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}




