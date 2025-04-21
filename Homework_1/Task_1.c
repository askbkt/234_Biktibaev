#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
    int x, y;

    printf("Enter value for x: ");
    scanf("%d", &x);

    printf("Enter value for y: ");
    scanf("%d", &y);

    printf("\nBefore swap:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    swap(&x, &y);

    printf("\nAfter swap:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}