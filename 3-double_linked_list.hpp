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
            delete toDel;
        }
        head = tail = nullptr;
        size = 0;
    }

    int getSize() const { return size; }
    int isEmpty() const { return size == 0; }

    // 头插
    void push_front(const T &value)
    {
        Node *newNode = new Node(value, nullptr, head);
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
        size++;
    }

    // 尾插
    void push_back(const T &value)
    {
        Node *newNode = new Node(value, tail, nullptr);
        if (tail != nullptr)
        {
            tail->next = newNode;
        }
        else
        {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    // 头删
    void pop_front()
    {
        if (isEmpty())
            throw runtime_error("链表为空");
        Node *toDel = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete toDel;
        size--;
    }

    // 尾删
    void pop_back()
    {
        if (isEmpty())
            throw runtime_error("链表为空");
        Node *toDel = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete toDel;
        size--;
    }

    // 在指定位置插入
    void insert(int pos, const T &value)
    {
        if (pos < 0 || pos > size)
            throw out_of_range("插入位置越界");
        if (pos == 0)
        {
            push_front(value);
            return;
        }
        if (pos == size)
        {
            push_back(value);
            return;
        }
        Node *cur = head;
        for (int i = 0; i < pos; i++)
            cur = cur->next;
        Node *pre = cur->prev;
        Node *newNode = new Node(value, pre, cur);
        pre->next = newNode;
        cur->prev = newNode;
        size++;
    }

    // 删除指定位置节点
    void remove(int pos)
    {
        if (pos < 0 || pos >= size)
            throw out_of_range("删除的位置越界");
        if (pos == 0)
        {
            pop_front();
            return;
        }
        if (pos == size - 1)
        {
            pop_back();
            return;
        }
        Node *toDel = head;
        for (int i = 0; i < = pos; i++)
            toDel = toDel->next;
        Node *pre = toDel->prev;
        Node *nex = toDel->next;
        pre->next = nex;
        nex->prev = pre;
        delete toDel;
        size--;
    }

    // 按值删除第一个匹配项
    bool removeByValue(const T &value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (current == head)
                    pop_front();
                else if (current == tail)
                    pop_back();
                else
                {
                    Node *pre = toDel->prev;
                    Node *nex = toDel->next;
                    pre->next = nex;
                    nex->prev = pre;
                    delete current;
                    size--;
                }
                return true;
            }
            current = current->next;
        }
        return false;
    }
};