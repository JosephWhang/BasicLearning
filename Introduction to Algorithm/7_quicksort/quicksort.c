/*
*   QuickSort
*   author: joseph
*   date: 2019-10-03 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 10

void swap(int *a, int *b);
int Partition(int *a, int p, int r);
int RandomPartition(int *a, int p, int r);
void QuickSort(int *a, int p, int r);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *a, int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j=p; j<r; j++) {
        if (a[j] < x) {
            i = i + 1;
            swap(&a[j], &a[i]);
        }
    }
    swap(&a[i+1], &a[r]);
    // for (int i=0; i<ARR_SIZE; i++) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    return i+1;
}

int RandomPartition(int *a, int p, int r)
{
    srand((unsigned)time(NULL));
    int i = rand() % (r - p + 1) + p;
    // printf("pivot:%d--", a[i]);
    swap(&a[i], &a[r]);
    return Partition(a, p, r);
}

void QuickSort(int *a, int p, int r)
{
    if (p < r) {
        int q = RandomPartition(a, p, r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    } 
}

int main()
{
    int arr[ARR_SIZE] = {10, 5, 8, 12, 1, 3, 4, 9, 15, 2}, *p;
    p = arr;
    QuickSort(p, 0, ARR_SIZE-1);

    printf("final:");
    for (int i=0; i<ARR_SIZE; i++) {
        printf("%d ", arr[i]);
    }
}