#include <iostream>
// cmath for isnan function
#include <cmath>

using namespace std;

int main()
{
    // Operands must be floats for division, but does interfere with modulo operator.
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

        // Perform operation and print the result.
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
            if (isnan(operand1 / operand2))
            {
                cout << "Divide by zero error.\n";
            }
            else
            {
                cout << operand1 / operand2 << endl;
            }
        }
        else if (operation == "%")
        {
            cout << (int)operand1 % (int)operand2 << endl;
        }

        // Now check for additional calculations
        cout << "Would you like to perform additional calculations (1/0): ";
        cin >> repeat;

    } while (repeat);

    return 0;
}