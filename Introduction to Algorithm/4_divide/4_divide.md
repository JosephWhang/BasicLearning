# 分治策略

本章介绍了分治策略，并列举了几个例子：1）最大子数组；2）矩阵乘法

## 分治法

分治法包含三个步骤
- 分解（Divide）—— 将问题划分为一些子问题，子问题的形式与原问题一样，只是规模更小
- 解决（Conquer）—— 递归求解子问题。如果子问题足够小，则停止递归，直接求解。（递归情况&基本情况）
- 合并（Combine）—— 将子问题的解组合成原问题的解。

## 递归式

通常分治法最后会得到一个递归式，描述算法的运行效率：
```
T(n) = O(1)             when n = 1;
       2T(n/2) + O(n)   when n > 1;
```

求解递归式通常有三种方式：
- 代入法
- 递归树法（参考归并排序）
- 主方法（本章主要讨论这种方法）  
    T(n) = aT(n/b) + f(n)  
    其中a>=1, b>1, f(n)是一个给定函数。  
    刻画了分治法生成了a个子问题，每个子问题的规模是原问题规模的1/b，分解和合并步骤总共花费时间为f(n)。

## 最大子数组问题

对于一个给定数组（值这里简化为整数），求其一个连续子数组，其和最大，这个问题成为最大子数组问题。

### 分治策略

如[max_subarray_sum.c](max_subarray_sum.c)所示

```
FIND-MAXIMUM-SUBARRAY(A, low, high)
    if high == low
        return (low, high, A[low])
    else mid == (low + high) / 2
        (left-low, left-high, left-sum) 
            = FIND-MAXIMUM-SUBARRAY(A, low, mid)
        (right-low, right-high, right-sum)
            = FIND-MAXIMUM-SUBARRAY(A, mid+1, high)
        (cross-low, cross-high, cross-sum)
            = FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
        if left-sum >= right-sum and left-sum >= cross-sum
            return (left-low, left-high, left-sum)
        elseif right-sum >= left-sum and right-sum >= cross-sum
            return (right-low, right-high, right-sum)
        else return (cross-low, cross-high, cross-sum)

FIND-MAX-CROSSING-SUBARRAY(A, low, mid, high)
    left-sum = INT_MIN
    sum = 0
    for i = mid downto low
        sum = sum + A[i]
        if sum > left-sum
            left-sum = sum
            max-left = i
    right-sum = INT_MIN
    sum = 0
    for j = mid+1 downto high
    sum = sum + A[j]
    if sum > right-sum
        right-sum = sum
        max-right = j
    return (max-left, max-right, left-sum+right-sum)
```
