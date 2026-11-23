#include <iostream>
#define InitSize 50
typedef int ElemType;
using namespace std;

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