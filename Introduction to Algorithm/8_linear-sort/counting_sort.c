#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ARR_SIZE 10
int get_counting_sort_k_value(int *A);
int *counting_sort(int *A, int k);

int main()
{
    int arr[ARR_SIZE] = {6, 5, 8, 1, 1, 3, 4, 7, 5, 6}, *p;
    p = arr;

    int k = get_counting_sort_k_value(p);
    int *counting_sort_result = counting_sort(p, k);

    printf("counting sort:\n");
    for (int i=1; i<=ARR_SIZE; i++) {
        printf("%d ", counting_sort_result[i]);
    } 

    return 0;
}

int get_counting_sort_k_value(int *A)
{
    int max = INT_MIN;
    for (int i=0; i<ARR_SIZE; i++) {
        if (A[i] > max) max = A[i];
    }
    return max;
}

int *counting_sort(int *A, int k)
{
    int *B = (int *)malloc((ARR_SIZE+1)*sizeof(int));
    int *C = (int *)malloc((k+1)*sizeof(int));

    for (int i=0; i<=k; i++) C[i] = 0;
    for (int j=0; j<ARR_SIZE; j++) C[A[j]] += 1;
    for (int i=1; i<=k; i++) C[i] += C[i-1];
    for (int j=ARR_SIZE-1; j>=0; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]] -= 1;
    }

    return B;
}