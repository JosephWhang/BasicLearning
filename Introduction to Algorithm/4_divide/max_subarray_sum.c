/*
*   最大子数组问题
*   author: joseph
*   date: 2019-10-11
*/
#include <stdio.h>
#include <limits.h>

typedef struct 
{
    int low;    // 子数组的低位
    int high;   // 子数组的高位
    int value;  // 子数组值的和
}max_subarr;

void set_struct_value(max_subarr *p, int low, int high, int value);
max_subarr find_max_crossing_subarray(int *a, int low, int mid, int high);
max_subarr find_maximum_subarray(int *a, int low, int high);

int main()
{
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}, *p;
    p = arr;

    max_subarr subarr = find_maximum_subarray(p, 0, sizeof(arr) / sizeof(arr[0])-1);

    printf("the index of max_subarr is: %d -> %d\n", subarr.low, subarr.high);
    printf("the value of max_subarr is: %d", subarr.value);

    return 0;
}

max_subarr find_max_crossing_subarray(int *a, int low, int mid, int high)
{
    max_subarr subarr;

    // 向左走，找到最大和
    int left_max_sum = INT_MIN, left_sum = 0, left;
    for (int i=mid; i >= low; i--) {
        left_sum += a[i];
        if (left_sum > left_max_sum) {
            left_max_sum = left_sum;
            left = i;
        }
    }

    // 向右走，找到最大和
    int right_max_sum = INT_MIN, right_sum = 0, right;
    for (int i=mid+1; i <= high; i++) {
        right_sum += a[i];
        if (right_sum > right_max_sum) {
            right_max_sum = right_sum;
            right = i;
        }
    }

    set_struct_value(&subarr, left, right, left_max_sum + right_max_sum);
    return subarr;
}

max_subarr find_maximum_subarray(int *a, int low, int high)
{
    if (low == high) {
        max_subarr subarr;
        set_struct_value(&subarr, low, high, a[low]);
        return subarr;
    } else {
        int mid = (low + high) / 2;
        
        // 中点左边找最大子数组
        max_subarr subarr_left = find_maximum_subarray(a, low, mid);
        // 中点右边找最大子数组
        max_subarr subarr_right = find_maximum_subarray(a, mid+1, high);
        // 中点两边找最大子数组
        max_subarr subarr_both = find_max_crossing_subarray(a, low, mid, high);

        if (subarr_left.value > subarr_right.value && subarr_left.value > subarr_both.value) {
            return subarr_left;
        } else if (subarr_right.value > subarr_left.value && subarr_left.value > subarr_both.value) {
            return subarr_right;
        } else return subarr_both;
    }
}

void set_struct_value(max_subarr *p, int low, int high, int value)
{
    p->low = low;
    p->high = high;
    p->value = value;
}