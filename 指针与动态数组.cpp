#include <iostream>
using namespace std;

void swapByPointer(int *a, int *b);
void swapByReference(int &a, int &b);

int main()
{
    // 栈上数组(固定大小)
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 堆上动态数组(可变大小)
    int n = 10;
    int *heapArr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        heapArr[i] = i * i;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << heapArr[i] << " ";
    }

    cout << endl;

    // 释放堆上动态数组的内存
    delete[] heapArr;

    // 指针
    int *a = new int(10);
    int *b = new int(15);
    swapByPointer(a, b);
    cout << *a << " " << *b << endl;

    // 释放指针内存
    delete a;
    delete b;

    // 引用
    int c = 10;
    int d = 15;
    swapByReference(c, d);
    cout << c << " " << d << endl;

    return 0;
}

// 引用与指针的区别
void swapByPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}