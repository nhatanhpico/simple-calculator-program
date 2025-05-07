#include "mycalculator.h"
#include "mystack.h"
#include <iostream>

// Helper: Remove all spaces from a string.
string removeSpaces(const string& str) {
    string result;
    for (char c : str) {
        if (c != ' ')
            result.push_back(c);
    }
    return result;
}

// Helper: Return operator precedence (higher number = higher precedence)
int precedence(char op) {
    if (op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

MyCalculator::MyCalculator(const string& infixExpr)
{
    // Normalize the infix expression by removing spaces.
    _infix = removeSpaces(infixExpr);
    _postfix = "";
}

string MyCalculator::infix()
{
    return _infix;
}

string MyCalculator::toPostfix()
{
    string output;
    MyStack opStack(100); // Stack for operators (sufficient capacity)

    for (char c : _infix) {
        if (c >= '0' && c <= '9') {
            output.push_back(c);
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(')
                opStack.pop();
        }
        else if (c == '+' || c == '-' || c == '*') {
            while (!opStack.empty() && opStack.top() != '(' &&
                   precedence(opStack.top()) >= precedence(c)) {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(c);
        }
        // Any other characters are ignored.
    }
    while (!opStack.empty()) {
        output.push_back(opStack.top());
        opStack.pop();
    }
    _postfix = output;
    return _postfix;
}

string MyCalculator::postfix()
{
    if (_postfix.empty())
        toPostfix();
    return _postfix;
}

int MyCalculator::evaluate()
{
    // Ensure postfix is computed.
    if (_postfix.empty())
        toPostfix();

    // Use a fixed-size integer stack.
    int evalStack[100];
    int topIndex = 0;

    for (char c : _postfix) {
        if (c >= '0' && c <= '9') {
            evalStack[topIndex++] = c - '0';
        }
        else if (c == '+' || c == '-' || c == '*') {
            if (topIndex < 2)
                return 0; // error: insufficient operands
            int b = evalStack[--topIndex];
            int a = evalStack[--topIndex];
            int result = 0;
            if (c == '+') result = a + b;
            else if (c == '-') result = a - b;
            else if (c == '*') result = a * b;
            evalStack[topIndex++] = result;
        }
    }
    if (topIndex == 1)
        return evalStack[0];
    else
        return 0; // error condition
}
