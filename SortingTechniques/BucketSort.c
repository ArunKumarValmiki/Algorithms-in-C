#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float* buckets[BUCKET_COUNT];
    int bucketSize[BUCKET_COUNT];

    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        bucketSize[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_COUNT;
        buckets[index][bucketSize[index]++] = arr[i];
    }

    for (int i = 0; i < BUCKET_COUNT; i++)
        insertionSort(buckets[i], bucketSize[i]);

    int idx = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSize[i]; j++)
            arr[idx++] = buckets[i][j];
        free(buckets[i]);
    }
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter elements (between 0 and 1):\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}
