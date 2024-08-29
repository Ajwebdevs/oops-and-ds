#include <stdio.h>

#define MAX 100

struct SparseMatrix {
    int row;
    int col;
    int value;
};

void addSparseMatrices(struct SparseMatrix a[], int aSize, struct SparseMatrix b[], int bSize, struct SparseMatrix result[]) {
    int i = 1, j = 1, k = 1;
    
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Matrices cannot be added!\n");
        return;
    }
    
    result[0].row = a[0].row;
    result[0].col = a[0].col;
    
    while (i <= aSize && j <= bSize) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            result[k].row = a[i].row;
            result[k].col = a[i].col;
            result[k].value = a[i].value + b[j].value;
            i++;
            j++;
            k++;
        } else if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k] = a[i];
            i++;
            k++;
        } else {
            result[k] = b[j];
            j++;
            k++;
        }
    }
    
    while (i <= aSize) {
        result[k++] = a[i++];
    }
    
    while (j <= bSize) {
        result[k++] = b[j++];
    }
    
    result[0].value = k - 1;
}

int main() {
    int aSize, bSize, i;
    struct SparseMatrix a[MAX], b[MAX], result[MAX];
    
    // Input first sparse matrix
    printf("Enter the number of non-zero elements in the first matrix: ");
    scanf("%d", &aSize);
    printf("Enter rows, columns and values:\n");
    for (i = 0; i <= aSize; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }
    
    // Input second sparse matrix
    printf("Enter the number of non-zero elements in the second matrix: ");
    scanf("%d", &bSize);
    printf("Enter rows, columns and values:\n");
    for (i = 0; i <= bSize; i++) {
        scanf("%d %d %d", &b[i].row, &b[i].col, &b[i].value);
    }
    
    addSparseMatrices(a, aSize, b, bSize, result);
    
    // Print the resultant matrix
    printf("Resultant matrix:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= result[0].value; i++) {
        printf("%d\t%d\t%d
