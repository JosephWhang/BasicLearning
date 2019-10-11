# 快排

## 分治法

1. Divide:
- Partition (rearrange) the array A[p...r] into two (possibly empty) subarrays A[p...q-1] and A[q+1...r]
- such that each elements of A[p...q-1] is less than or equal to A[q]
- which is, in turn, less than or equal to each element of A[q+1...r]
- conpute the index q as part of this partitioning procedure

2. Conquer
- Sort the two subarrays A[p...q-1] and A[q+1...r] by recursive calls to quicksort

3. Combine
- Since the subarrays are sorted in place, no work is needed to combine them: the entire array A[p...r] is now sorted

## 一般快排

1. 排序算法
```
QUICKSORT(A, p, r):
    if p < r
        q = PARTITION(A, p, r)
        QUICKSORT(A, p, q-1)
        QUICKSORT(A, q+1, r)
```

2. 划分算法
```
PARTITION(A, p, r)
    x = A[r]
    i = p-1
    for j=p to r-1
        if A[j] < x
            i = i+1
            exchange A[i] with A[j]
    exchange A[i+1] with A[r]
    return i+1
```

## 随机化快排
由于一般快排总是选择数组的最后一位作为主元，可能造成划分不平衡的情况，使得算法复杂度呈现最坏状态，即O(n^2)；随机化快排每次总是随机地从r-p+1个元素中选择一个作为主元。

1. 快排算法
```
RANDOMIZED-QUICKSORT(A, p, r):
    if p < r
        q = RANDOMIZED-PARTITION(A, p, r)
        RANDOMIZED-QUICKSORT(A, p, q-1)
        RANDOMIZED-QUICKSORT(A, q+1, r)
```

2. 划分算法
```
RANDOMIZED-PARTITION(A, p, r)
    i = RANDOM(p, r)
    exchange A[r] with A[i]
    return PARTITION(A, p, r)
```
PARTITION(A, p, r)与上述一般快排一致

## 时间复杂度

1. 最坏时间复杂度
O(n^2)

2. 一般时间复杂度
O(n * lgn)

## Q&A

- 为什么log10/9(n) = O(lgn)？
- 为什么max(q^2 + (n-q-1)^2), 0 <= q <= n-1, 的上界为 (n-1)^2？