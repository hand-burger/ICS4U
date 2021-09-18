#include <iostream>

using namespace std;

int main()
{
    float operand1, operand2;
    string operation;
    bool repeat;

    do
    {
        cout << "Enter first operand: ";
        cin >> operand1;
        cout << "Enter second operand: ";
        cin >> operand2;
        cout << "Enter the operator: ";
        cin >> operation;

        cout << operand1 << operation << operand2 << "=";

        if (operation == "+")
        {
            cout << operand1 + operand2 << endl;
        }
        else if (operation == "-")
        {
            cout << operand1 - operand2 << endl;
        }
        else if (operation == "*")
        {
            cout << operand1 * operand2 << endl;
        }
        else if (operation == "/")
        {
            cout << operand1 / operand2 << endl;
        }
        else if (operation == "%")
        {
            cout << (int)operand1 % (int)operand2 << endl;
        }

        cout << "Would you like to perform additional calculations (1/0): ";
        cin >> repeat;

    } while (repeat);

    return 0;
}