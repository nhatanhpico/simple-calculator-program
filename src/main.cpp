#include <iostream>
#include <string>
#include "mycalculator.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " \"expression\"" << endl;
        return 1;
    }
    string expression = argv[1];
    MyCalculator calc(expression);
    cout << "Infix: " << calc.infix() << endl;
    cout << "Postfix: " << calc.postfix() << endl;
    cout << "Evaluate: " << calc.evaluate() << endl;
    return 0;
}
