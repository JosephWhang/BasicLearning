# 中位数与顺序统计量

- 在一个由n个元素组成的集合中，第i个顺序统计量是该集合中第i小的元素。
- 在一个元素集合中，最小值是第一个顺序统计量（i=1），最大值是第n个顺序统计量（i=n）。
- 中位数出现在i=(n+1)/2（向下取整）（下中位数）。

**本章的问题**
```
一个选择问题：
输入：一个包含n个（互异的）数的集合A和一个整数i，1=<i<=n。
输出：元素x属于A，且A中恰好有i-1个其他元素小于它。
```

## 最大值和最小值

- 选最大值或最小值最优算法，n-1次比较。
```
MINIMUM(A)
    min = A[1]
    for i=2 to A.length
        if min > A[i]
            min = A[i]
    return min
```
- 同时选最大值和最小值算法，至多3*[n/2]（向下取整）次比较。
```
MAX_AND_MIN(A)
    min = 0
    max = 0
    i = 0
    if A.length mod 2 == 0
        (min, max) = CMP(A[1], A[2])
        i = 3
    else 
        min = max = A[1]
        i = 2
    for i to A.length (i += 2)
        min_curr, max_curr = CMP(A[i], A[i+1])
        if min_curr < min 
            min = min_curr
        if max_curr > max
            max = max_curr
    return (min, max)
```

## 期望为线性时间的选择算法

```
RANDOMIZED-SELECT(A, p, r, i)
    if p == r
        return A[p]
    q = RANDOMIZED-PARTITION(A, p, r)
    k = q - p + 1
    if i = k
        return A[q]
    else if i < k
        return RANDOMIZED-SELECT(A, p, q - 1, i)
    else return RANDOMIZED-SELECT(A, q+1, r, i)
```

