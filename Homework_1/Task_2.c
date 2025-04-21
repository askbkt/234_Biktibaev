#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size. Bye!\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nReversed array:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}