// 单向链表模板类
#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;

        // 构造函数
        Node(const T &value, Node *nxt = nullptr) : data(value), next(nxt)
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
    // 成员函数尾部 const修饰this 指针（当前类对象本身），保护本类的成员变量不被修改。
    int getSize() const { return size; }
    int isEmpty() const { return size == 0; }
};