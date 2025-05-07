#ifndef MYSTACK_H
#define MYSTACK_H

#include <string>
using namespace std;

class MyStack 
{
public:
    MyStack(int capacity = 10);
    ~MyStack();

    int size();
    void push(char ch);
    char top();
    void pop();
    bool full();
    bool empty();
    std::string toString();

private:
    char *_arr;
    int _capacity;   // Maximum number of elements the stack can hold
    int _top;        // Current number of elements (index for next push)
};

#endif
