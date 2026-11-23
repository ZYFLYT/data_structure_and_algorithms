#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>

class ArrayList
{
private:
    T *data;      // 指向堆数组的指针
    int capacity; // 当前最大容量
    int size;     // 实际元素个数

    void resize()
    {
        int newCap = capacity * 2;
        T *newData = new T[newCap];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCap;
        cout << "扩容至 " << capacity << endl;
    }

public:
    // 构造函数
    ArrayList(int initCap = 10)
    {
        capacity = initCap;
        size = 0;
        data = new T[capacity];
    }
    // 析构函数
    ~ArrayList()
    {
        delete[] data;
    }

    // 获取大小和容量
    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }

    // 在末尾添加元素
    void push_back(const T &value)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size++] = value;
    }

    // 在指定位置插入元素
    void insert(int pos, const T &value)
    {
        if (pos < 0 || pos > size)
        {
            throw out_of_range("插入位置越界");
        }
        if (size == capacity)
        {
            resize();
        }
        for (int i = size; i > pos; i--)
        {
            data[i] = data[i - 1];
        }
        data[pos] = value;
        size++;
    }

    // 删除指定位置的元素
    void remove(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            throw out_of_range("删除位置越界");
        }
        for (int i = pos; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    // 访问(重载[])
    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("索引越界");
        }
        return data[index];
    }
    // const版本
    const T &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("索引越界");
        }
        return data[index];
    }

    // 打印
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // 清空
    void clear()
    {
        size = 0;
    }

    // 将容量缩小为当前实际大小
    void shrink_to_fit()
    {
        if (capacity <= size)
            return;
        int newCap = size == 0 ? 1 : size;
        T *newData = new T[newCap];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }

    // 查询索引
    int find(const T &value) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
                return i;
        }
        return -1; // 未找到
    }
};