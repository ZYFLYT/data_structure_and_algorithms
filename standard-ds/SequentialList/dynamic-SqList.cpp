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