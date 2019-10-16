# 线性时间排序

## 比较排序算法的下界

## 计数排序

```
COUNTING-SORT(A, B, k)
    for i = 1 to k
        C[i] = 0
    for j = 1 to A.length
        C[A[j]] = C[A[j]] + 1
    for i = 2 to k
        C[i] = C[i] + C[i-1]
    for j = A.length to 1
        B[C[A[j]]] = A[j]
        C[A[j]] = C[A[j]] - 1
```

## Q&A

- 如何事先确定计数排序中的K值，是重新遍历一遍取最大值吗？