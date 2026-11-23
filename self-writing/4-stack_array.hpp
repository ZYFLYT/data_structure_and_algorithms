#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class StackArray
{
private:
    T *data;
    int top; // 栈顶指针，指向栈顶元素的下一个位置（初始为0)
    int capacity;
}