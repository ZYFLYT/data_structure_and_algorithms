#include "3-double_linked_list.hpp"
#include <iostream>

int main()
{
    using namespace std;

    DoubleLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    list.push_front(1);

    cout << "初始: ";
    list.print(); // [1 5 10 20 30]

    list.insert(2, 999);
    cout << "插入999在位置2: ";
    list.print(); // [1 5 999 10 20 30]

    list.remove(3);
    cout << "删除位置3: ";
    list.print(); // [1 5 999 20 30]

    list.reverse();
    cout << "反转: ";
    list.print(); // [30 20 999 5 1]

    cout << "查找20的索引: " << list.find(20) << endl; // 1

    list.clear();
    cout << "清空后size: " << list.getSize() << endl;

    return 0;
}