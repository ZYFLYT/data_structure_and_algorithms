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
};