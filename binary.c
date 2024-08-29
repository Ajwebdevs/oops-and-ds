#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, key, i, result;
    
    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input sorted array elements
    printf("Enter sorted elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    result = binarySearch(arr, 0, n-1, key);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
