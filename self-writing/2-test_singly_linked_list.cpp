#include "2-singly_linked_list.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "========== 单链表完整测试 ==========" << endl;

    // 1. 测试构造、尾插、头插、打印
    SinglyLinkedList<int> list;
    cout << "创建空链表，size = " << list.getSize() << endl;
    cout << endl;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);
    list.push_front(1);
    cout << "经过 push_back(10,20,30) 和 push_front(5,1) 后：" << endl;
    list.print(); // 预期 [1, 5, 10, 20, 30]
    cout << "size = " << list.getSize() << endl;
    cout << endl;

    // 2. 测试插入（中间）
    list.insert(3, 999);
    cout << "在位置 3 插入 999 后：" << endl;
    list.print(); // 预期 [1, 5, 10, 999, 20, 30]
    cout << endl;

    // 3. 测试删除（按位置）
    list.remove(2);
    cout << "删除位置 2（原 10）后：" << endl;
    list.print(); // 预期 [1, 5, 999, 20, 30]
    cout << endl;

    // 4. 测试按值删除
    bool removed = list.removeByValue(999);
    cout << "按值删除 999 " << (removed ? "成功" : "失败") << endl;
    list.print(); // 预期 [1, 5, 20, 30]
    cout << endl;

    // 5. 测试反转
    list.reverse();
    cout << "反转链表后：" << endl;
    list.print(); // 预期 [30, 20, 5, 1]
    cout << endl;

    // 6. 测试 [] 访问及修改
    cout << "list[2] = " << list[2] << endl; // 应为 5
    list[2] = 777;
    cout << "修改 list[2] = 777 后：" << endl;
    list.print(); // 预期 [30, 20, 777, 1]
    cout << endl;

    // 7. 测试查找
    int pos = list.find(20);
    cout << "查找值 20 的索引：" << pos << endl; // 应为 1
    pos = list.find(999);
    cout << "查找不存在的 999 返回：" << pos << endl; // -1
    cout << endl;

    // 8. 测试清空
    list.clear();
    cout << "清空后 size = " << list.getSize() << endl;
    list.print(); // 空
    cout << endl;

    // 9. 边界测试：对空链表删除/访问应抛异常
    try
    {
        list.remove(0);
    }
    catch (const out_of_range &e)
    {
        cout << "捕获异常（空链表删除）：" << e.what() << endl;
    }
    cout << endl;

    try
    {
        list[0] = 1;
    }
    catch (const out_of_range &e)
    {
        cout << "捕获异常（空链表访问）：" << e.what() << endl;
    }
    cout << endl;

    // 10. 测试字符串类型
    SinglyLinkedList<string> strList;
    strList.push_back("Hello");
    strList.push_back("World");
    strList.insert(1, "C++");
    cout << "字符串链表：" << endl;
    strList.print(); // 预期 [Hello, C++, World]

    cout << "========== 所有测试完成 ==========" << endl;

    return 0;
}