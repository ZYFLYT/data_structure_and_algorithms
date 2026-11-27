#include <iostream>
#define InitSize 50
typedef int ElemType;
using namespace std;

typedef struct
{
    ElemType *data;
    int length;
    int maxSize;
} DynList;

void InitDynList(DynList &L)
{
    L.data = new ElemType[InitSize];
    L.length = 0;
    L.maxSize = InitSize;
}

void DestroyList(DynList &L)
{
    delete[] L.data;
    L.data = NULL;
    L.length = 0;
    L.maxSize = 0;
}

void ClearList(DynList &L) { L.length = 0; }

bool ListEmpty(DynList L) { return L.length == 0; }

int ListLength(DynList L) { return L.length; }

// 按位查找
bool GetElem(DynList L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    return true;
}

// 按值查找
int LocateElem(DynList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

// 求前驱
bool PriorElem(DynList L, ElemType cur, ElemType &pre)
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
bool NextElem(DynList L, ElemType cur, ElemType &next)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == cur)
        {
            if (i = L.length - 1)
                return false;
            next = L.data[i + 1];
            return true;
        }
    }
    return false;
}

// 动态插入
bool ListInsert(DynList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= L.maxSize)
        return false;

    for (int j = L.length; j >= 1; j--)
        L.data[j] = L.data[j - 1];

    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(DynList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

void ListTraverse(DynList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " " << endl;
    }
}

// 扩容
void IncreaseSize(DynList &L, int len)
{
    ElemType *p = L.data;
    L.data = new ElemType[L.maxSize + len];
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    delete[] p;
    L.maxSize += len;
}
