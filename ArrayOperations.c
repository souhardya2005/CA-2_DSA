#include <stdio.h>

#define MAX 100

void insert(int arr[], int *n, int element, int pos) {
    if (*n == MAX) {
        printf("Array is full, cannot insert element.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (*n == 0) {
        printf("Array is empty, cannot delete element.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n = 0, choice, element, pos, key, result;

    do {
        printf("\nMenu:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Linear Search\n");
        printf("4. Binary Search\n");
        printf("5. Display Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                insert(arr, &n, element, pos);
                break;

            case 2:
                printf("Enter position of element to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;

            case 3:
                printf("Enter element to search (Linear Search): ");
                scanf("%d", &key);
                result = linearSearch(arr, n, key);
                if (result != -1) {
                    printf("Element found at position %d.\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 4:
                printf("Enter element to search (Binary Search): ");
                scanf("%d", &key);
                result = binarySearch(arr, n, key);
                if (result != -1) {
                    printf("Element found at position %d.\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 5:
                display(arr, n);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
