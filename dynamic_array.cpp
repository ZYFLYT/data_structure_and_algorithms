#include <iostream>
#include "arraylist_template.hpp"
using namespace std;

int main()
{
    // system("chcp 65001 > nul");
    // 测试
    ArrayList<int> list(3);
    cout << "初始容量: " << list.getCapacity() << endl;
    for (int i = 0; i <= 5; i++)
    {
        list.push_back(i * 10);
        list.print();
        cout << "当前大小: " << list.getSize() << ", 当前容量: " << list.getCapacity() << endl;
    }

    list.insert(2, 999);
    list.print();

    list.remove(4);
    list.print();

    list[1] = 888;
    list.print();

    return 0;
}