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
    // Invalid input flag
    bool invalid = false;

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
            invalid = true;
            cout << "Invalid operation.\n";
        }

        // Output the result if operation was valid
        if (!invalid)
        {
            cout << "Equals: " << result << endl;
        }
        cout << "Would you like to perform additional calculations (y/n): ";
        cin >> operation;
        // Check if user wants to continue
    } while (operation != 'n' && operation == 'y');
    return 0;
}