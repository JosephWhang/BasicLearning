# 堆

本章介绍了堆的这种数据结构，以及应用于排序和优先级队列的算法原理和实现。

## 堆的基本性质和基本操作
give an array A like: {16, 14, 10, 8, 7, 9, 3, 2, 4, 1}  
draw a max-heap from left to right and top to bottom like: 
```  
16
14 10
8  7  9  3
2  4  1
```  
1. **最大堆和最小堆的性质**
- A[PARENT(i)] >= A[i]  大
- A[PARENT(i)] <= A[i]  小
2. **数组A的两个变量，heap-size在构造最大(小)堆时有用**
- A.length                          (通常)给出数组元素的个数
- A.heap-size                       表示有多少堆元素存储在数组中  
3. **下述用宏定义(或内联函数)实现，通过移位操作实现，速度更快。**
- PARENT(i) return i/2;(向下取整)    返回父节点    
- LEFT(i) return 2i;                返回左孩子
- RIGHT(i) return 2i+1;             返回右孩子  
4. **维护堆的性质**
- MAX-HEAPIFY(A, i)     
- MIN-HEAPIFY(A, i)    输入一个堆数组A和元素下标，将该元素调整到堆正确的位置
5. **建堆**
- BUILD-MAX-HEAP(A)    
- BUILD-MIN-HEAP(A)    输入一个堆数组A，构造其为一个最大(小)堆

## 堆排序算法

算法的基本思想：首先利用BUILD-MAX-HEAP(A)构造一个堆；然后每次将A[1]和A[n]替换，接着去掉n节点(即当前堆堆大的元素节点)，此时A[1]不满足最大堆特性，则调用MAX-HEAPIFY(A, 1)进行维护；重复以上。  
1. **堆排序算法**
- HEAPSORT(A)   将堆数组A进行排序

## 优先队列





