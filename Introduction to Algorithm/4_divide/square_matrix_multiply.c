/*
*   矩阵相乘
*   author: joseph
*   date: 2019-10-13
*/
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 4
int **square_matrix_multiply_general(int A[MATRIX_SIZE][MATRIX_SIZE], int B[MATRIX_SIZE][MATRIX_SIZE]);

int main()
{
    /* 用二维数组定义两个矩阵
       运算结果：
        97 86 45 55
        66 82 37 81
        106 126 62 113
        69 59 32 44
    */
    int matrix_a[MATRIX_SIZE][MATRIX_SIZE] = {
        {2, 8, 3, 4}, 
        {3, 3, 7, 1},
        {5, 6, 9, 2},
        {2, 6, 3, 1}
    };
    int matrix_b[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 8, 7, 4}, 
        {8, 3, 2, 1},
        {5, 6, 1, 9},
        {4, 7, 3, 3}
    };

    // 一般矩阵乘法，O(n^3)
    int **matrix_general = square_matrix_multiply_general(matrix_a, matrix_b);

    printf("general:\n");
    for (int i=0; i<MATRIX_SIZE; i++) {
        for (int j=0; j<MATRIX_SIZE; j++) {
            printf("%d ", *(*matrix_general + MATRIX_SIZE*i + j));
        }
        printf("\n");
    }

    return 0;
}

// 一般矩阵乘法
int **square_matrix_multiply_general(int A[MATRIX_SIZE][MATRIX_SIZE], int B[MATRIX_SIZE][MATRIX_SIZE])
{
    int n = MATRIX_SIZE;
    int **C = (int **)malloc(MATRIX_SIZE*sizeof(int *));
    for (int i=0; i<MATRIX_SIZE; i++) {
        C[i] = (int *)malloc(MATRIX_SIZE*sizeof(int));
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            *(*C + n*i + j) = 0;
            for (int k=0; k<n; k++) {
                *(*C + n*i + j) = *(*C + n*i + j) + A[i][k] * B[k][j];
            }
        }
    }

    return C;
}