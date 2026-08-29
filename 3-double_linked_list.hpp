#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <template T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;

        // = T() 是默认实参T() 叫值初始化
        // 对比单链表中的Node(const T &value, Node *nxt = nullptr)
        // 双链表中有个特殊的节点是哨兵节点,没有数值,但是有prev,next
        Node(const T &value = T(), Node *pre = nullptr, Node *nex = nullptr)
            : data(value), prev(pre), next(nex) {}
    };

    Node *sentinel; // 这是一个指针，指向堆上分配的哨兵节点
    int size;       // 有效节点的个数（哨兵不算）

public:
}