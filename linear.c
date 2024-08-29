#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
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
    
    // Input array elements
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    result = linearSearch(arr, n, key);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}
