#include <iostream>
#define InitSize 50
using namespace std;
#include "dynamic-SqList.cpp"

typedef struct
{
    int data[InitSize];
    int length;
} SqList;

typedef struct
{
    int *data;
    int length, maxSize;
} DynList;

// 一、逆置
void Reverse(SqList &L, int from, int to)
{
    while (from < to)
    {
        int t = L.data[from];
        L.data[from++] = L.data[to];
        L.data[to--] = t;
    }
}

// 二、删除所有值为x的元素
// 这里的k使用的快慢指针，k是慢指针，i是快指针
void DelAllX(SqList &L, int x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
}

// 三、删除值在(s,t)区间内的元素
bool DelRange(SqList &L, int s, int t)
{
    if (s >= t || L.length == 0)
    {
        return false;
    }
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] <= s || L.data[i] >= t)
        {
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
    return true;
}

// 有序表去重
void DelDup(SqList &L)
{
    if (L.length < 2)
    {
        return;
    }
    int k = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[k] != L.data[i]) // 这里就采用k最好而不是i-1，采用k后面选择性更多，比如可以多保留
        {
            L.data[++k] = L.data[i];
        }
    }
    L.length = k + 1;
}

// 有序表去重，相同的最多可以保留两个
void DelDup_2(SqList &L)
{
    if (L.length < 2)
    {
        return;
    }
    int k = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (k < 1 || L.data[k - 1] != L.data[i]) // 这里就是用k可以多保留
        {
            L.data[++k] = L.data[i];
        }
    }
    L.length = k + 1;
}

// 两个有序表归并
void MergeStatic(SqList &A, SqList &B, SqList &C)
{
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        C.data[k++] = (A.data[i] <= B.data[j]) ? A.data[i++] : B.data[j++];
    }
    while (i < A.length)
    {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length)
    {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
}

void MergeDynamic(DynList &A, DynList &B, DynList &C)
{
    int need = A.length + B.length;
    if (need > C.maxSize)
    {
        IncreaseSize(C, need - C.maxSize);
    }
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        C.data[k++] = (A.data[i] <= B.data[j]) ? A.data[i++] : B.data[j++];
    }
    while (i < A.length)
    {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length)
    {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
}

// 以首元素为枢轴划分(快排partition 原型)
// 挖坑法
void Partition(SqList &L)
{
    if (L.length <= 1)
    {
        return;
    }
    int pivot = L.data[0], left = 0, right = L.length - 1;
    while (left < right)
    {
        while (left < right && L.data[right] > pivot)
        {
            right--;
        }
        L.data[left] = L.data[right];

        while (left < right && L.data[left] < pivot)
        {
            left++;
        }
        L.data[right] = L.data[left];
    }
    L.data[left] = pivot;
}

// 循环左移 p 位，这个思路非常巧妙，仔细理解
void LeftRotate(SqList &L, int p)
{
    if (L.length == 0)
        return;
    if (p == 0)
        return;
    Reverse(L, 0, p - 1);
    Reverse(L, p, L.length - 1);
    Reverse(L, 0, L.length - 1);
}

// 循环右移p，利用左移
void RightRotate(SqList &L, int p)
{
    int x = L.length - p;
    if (L.length == 0)
        return;
    LeftRotate(L, x);
}