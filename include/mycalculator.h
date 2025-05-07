#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <string>
using namespace std;

class MyCalculator
{
public:
    MyCalculator(const string& infix);
    string infix();
    string postfix();
    string toPostfix();
    int evaluate();

private:
    string _infix;    // Normalized infix expression (no spaces)
    string _postfix;  // Converted postfix expression
};

#endif
