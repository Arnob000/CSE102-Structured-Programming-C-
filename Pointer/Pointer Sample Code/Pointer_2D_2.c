//
// Author: Saifur Rahman
// Last Modified: 16 JUL 2019
//

#include <stdio.h>
#include <stdlib.h>

//
// Read a matrix from console.
//
void readMatrix(int **mat, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);

            // Alternately, you can do pointer arithmetic by
            // commenting the above line and uncommenting the following line
            scanf("%d", *(mat + i) + j);
        }
    }
}

void printMatrix(int **mat, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);

            // Alternately, you can do pointer arithmetic by
            // commenting the above line and uncommenting the following line
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

//
// Sum the elements of an 1D array.
//
int sum(int x[], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += x[i];
    }

    return sum;
}

int main() {
    int **mat = NULL, r, c, i, j;

    //
    // Home work: Extend this program to deal with arbitrary number of
    // matrices. You will need a 3D integer pointer. And the first input
    // you take from console is the number of matrices. Then for each matrix
    // you take row and column size, followed by the elements in row major order
    //

    while (scanf("%d%d", &r, &c) == 2) {
        mat = (int **)malloc(r * sizeof(int*));
        for (i = 0; i < r; i++) {
            mat[i] = (int*)malloc(c * sizeof(int));
        }

        readMatrix(mat, r, c);
        printMatrix(mat, r, c);

        for (i = 0; i < r; i++) {
            printf("Row %d sum: %d\n", i, sum(mat[i], c));
        }

        for (i = 0; i < r; i++) {
            free(mat[i]);
        }
        free(mat);
    }


    return 0;
}
