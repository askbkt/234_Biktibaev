#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;

    printf("Enter matrix size (rows cols): ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Invalid dimensions. Try again.\n");
        return 1;
    }

    int **matrix = (int **)malloc(rows * sizeof(int *));
    int **transposed = (int **)malloc(cols * sizeof(int *));
    if (!matrix || !transposed) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < cols; i++) {
        transposed[i] = (int *)malloc(rows * sizeof(int));
    }

    printf("Enter matrix values (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    printf("\nTransposed matrix (%d x %d):\n", cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) free(matrix[i]);
    for (int i = 0; i < cols; i++) free(transposed[i]);
    free(matrix);
    free(transposed);

    return 0;
}