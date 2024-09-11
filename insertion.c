#include <stdio.h>

void insert(int arr[], int *n, int pos, int value) {
    
    for (int i = *n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
   
    arr[pos] = value;
    
    (*n)++;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};  
    int n = 5; 
    int pos = 2; 
    int value = 10; 

    printf("Array before insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insert(arr, &n, pos, value); 

    printf("\nArray after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
