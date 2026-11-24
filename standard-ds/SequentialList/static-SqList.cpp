#include <iostream>
#define InitSize 50
typedef int ElemType;
using namespace std;

// 静态顺序表
typedef struct
{
    ElemType data[InitSize];
    int length;
} SqList;

void InitList(SqList &L)
{
    L.length = 0;
}

void ClearSqList(SqList &L) { L.length = 0; }

bool ListEmpty(SqList L) { return L.length == 0; }

int ListLength(SqList L) { return L.length; }

// 按位查找
bool GetElem(SqList L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    return true;
}

// 按值查找
int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

// 求前驱
bool PriorElem(SqList L, ElemType cur, ElemType &pre)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == cur)
        {
            if (i == 0)
                return false;
            pre = L.data[i - 1];
            return true;
        }
    }
    return false;
}

// 求后继
bool NextElem(SqList L, ElemType cur, ElemType &next)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == cur)
        {
            if (i == L.length - 1)
                return false;
            next = L.data[i + 1];
            return true;
        }
    }
    return false;
}

// 静态插入
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= InitSize)
        return false;

    for (int j = L.length; j >= 1; j--)
        L.data[j] = L.data[j - 1];

    L.data[i - 1] = e;
    L.length++;
    return true;
}