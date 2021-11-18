#include <iostream>

using namespace std;

int main()
{
    // Five function calculator
    // 1. Addition
    // 2. Subtraction
    // 3. Multiplication
    // 4. Division
    // 5. Modulus

    // Declare variables
    int num1, num2, result;
    char operation;

    do
    {
        // Prompt user for input
        cout << "Enter two numbers and an operation in one line (+ - / * %): ";
        cin >> num1 >> operation >> num2;

        // Perform operation
        switch (operation)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '%':
            result = num1 % num2;
            break;
        default:
            cout << "Invalid operation.\n";
            break;
        }

        // Output the result
        cout << "Equals: " << result << endl;
        cout << "Would you like to perform additional calculations (y/n): ";
        cin >> operation;
    } while (operation != 'n' && operation == 'y');
    return 0;
}