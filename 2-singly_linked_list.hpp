// 单向链表模板类
#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;

        // 构造函数
        Node(const T &value, Node *nxt = nullptr) : data(value), next(nxt) {}
    };

    // 成员变量
    Node *head;
    int size;

public:
    // 构造函数
    SinglyLinkedList() : head(nullptr), size(0) {}

    // 析构函数
    ~SinglyLinkedList()
    {
        clear();
    }

    // 基本访问函数
    // 参数的 const：修饰传入的形参，保护函数内部不要修改传入过来的实参。
    // const T& operator[](...) 调用方不能通过这个返回值去修改链表里面的数据。
    // 成员函数尾部 const修饰this 指针（当前类对象本身），保护本类的成员变量不被修改。
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

    // 清空链表
    void clear()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *toDelete = current; // 创建一个临时变量保存当前节点
            current = current->next;
            delete toDelete;
        }
        head = nullptr;
        size = 0;
    }

    // 头插法
    void push_front(const T &value)
    {
        head = new Node(value, head);
        ++size;
    }

    // 尾插法
    void push_back(const T &value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new Node(value);
        }
        ++size;
    }

    // 在指定位置插入
    void insert(int pos, const T &value)
    {
        if (pos < 0 || pos > size)
        {
            throw out_of_range("插入的位置越界");
        }
        if (pos == 0)
        {
            push_front(value);
            return;
        }
        // 找到pos的前一个位置
        Node *preview = head;
        for (int i = 0; i < pos - 1; i++)
        {
            preview = preview->next;
        }
        Node *newNode = new Node(value, preview->next);
        preview->next = newNode;

        ++size;
    }

    // 删除指定位置
    void remove(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            throw out_of_range("删除的位置越界");
        }
        Node *toDelete = nullptr;

        if (pos == 0)
        {
            toDelete = head;
            head = head->next;
            delete toDelete;
        }
        else
        {
            Node *preview = head;
            for (int i = 0; i < pos - 1; i++)
            {
                preview = preview->next;
            }
            toDelete = preview->next;
            preview->next = toDelete->next;
        }
        delete toDelete;
        --size;
    }

    // 按值删除第一个匹配的节点
    // 若找到并删除，返回 true；否则返回 false
    // 时间复杂度 O(n)
    bool removeByValue(const T &value)
    {
        if (head == nullptr)
        {
            return false;
        }

        if (head->data == value)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            --size;
            return true;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == value)
            {
                Node *toDelete = current->next;
                current->next = toDelete->next;
                delete toDelete;
                --size;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // 原地反转链表（经典三指针法）
    // 改变所有节点的 next 方向，不创建新节点
    // 时间复杂度 O(n)，空间复杂度 O(1)
    void reverse()
    {
        Node *preview = nullptr;
        Node *current = head;
        Node *nextTemp = nullptr;
        while (current != nullptr)
        {
            nextTemp = current->next;
            current->next = preview;
            preview = current;
            current = nextTemp;
        }
        head = preview;
    }

    // 线性查找：返回 value 第一次出现的索引，未找到返回 -1
    // 时间复杂度 O(n)
    int find(const T &value) const
    {
        Node *current = head;
        int index = 0;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return index;
            }
            index++;
            current = current->next;
        }
        return -1;
    }

    // 重载 [] 运算符，支持类似数组的访问
    // 由于链表不支持随机访问，时间复杂度 O(n)
    // 提供 const 和非 const 两个版本
    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("索引越界");
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    const T &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("索引越界");
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    // 打印链表内容（用于调试）
    void print() const
    {
        Node *current = head;
        cout << "[ ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};