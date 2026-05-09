#include <stdio.h>

int binarySearchRecursive(int a[], int low, int high, int key) {
    if (low > high) {
        return -1; // Base case: Element not found
    }

    int mid = low + (high - low) / 2;

    if (a[mid] == key) {
        return mid; // Base case: Element found
    }

    if (key < a[mid]) {
        return binarySearchRecursive(a, low, mid - 1, key);
    } else {
        return binarySearchRecursive(a, mid + 1, high, key);
    }
}

int main() {
    int a[15], key, n = 15;

    printf("Exp_01_Binary_search_Recursive\n\n");
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearchRecursive(a, 0, n - 1, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
