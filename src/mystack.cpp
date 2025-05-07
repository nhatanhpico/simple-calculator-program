#include "mystack.h"
#include <iostream>

using namespace std;

MyStack::MyStack(int capacity)
    : _capacity(capacity), _top(0)
{
    _arr = new char[capacity];
}

MyStack::~MyStack()
{
    delete[] _arr;
}

int MyStack::size()
{   
    return _top;
}

void MyStack::push(char ch)
{
    if (!full()) {
        _arr[_top++] = ch;
    }
}

char MyStack::top()
{
    if (!empty())
        return _arr[_top - 1];
    else
        return '\0';
}

void MyStack::pop()
{
    if (!empty())
    {
        _top--;
    }
}

bool MyStack::full()
{
    return _top == _capacity;
}

bool MyStack::empty()
{
    return _top == 0;
}

string MyStack::toString()
{
    string result;
    for (int i = 0; i < _top; i++) {
        result.push_back(_arr[i]);
    }
    return result;
}
