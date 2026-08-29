#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
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

    Node *head; // 指向第一个节点（如果链表为空，则为 nullptr）
    Node *tail; // 指向最后一个节点（如果链表为空，则为 nullptr）
    int size;   // 有效节点的个数

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoubleLinkedList() { clear(); }

    void clear()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *toDel = current;
            current = current->next;
            delete current;
        }
        head = tail = nullptr;
        size = 0;
    }

    int getSize() const { return size; }
    int isEmpty() const { return size == 0; }
};