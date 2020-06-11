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

## 桶排序

桶排序假设输入数据服从均匀分布，平均情况下它的时间代价为O(n)。

### 基本思路
桶排序将输入看作一个随机过程产生，该过程将元素均匀、独立地分布在[0,1)区间上；桶排序将[0, 1)区间划分为n个大小相同的子区间，称为桶。然后将n个输入数分别放入各个桶中（因为输入数据是均匀、独立地分布在[0,1)区间上，所以一般不会出现很多数落在同一个桶中的情况）；为了得到输出结果，我们先对每个桶中的数进行排序，然后遍历每个桶，按照次序把各个桶中的元素列出来即可。

### 实现伪代码
输入是一个包含n个元素的数组A，且每个元素A[i]满足0 =< A[i] <= 1；临时数组B[0...n-1]存放链表，并用链表机制进行维护
```
BUCKET-SORT(A)
    n = A.length
    let B[0..n-1] be a new array
    for i=0 to n-1
        make B[i] an empty list
    for i=1 to n
        insert A[i] into list B[n*A[i]]
    for i=0 to n-1
        sort list B[i] with insertion sort
    concatenate the lists B[0], ... , B[n-1] together in order
```
## Q&A

- 如何事先确定计数排序中的K值，是重新遍历一遍取最大值吗？