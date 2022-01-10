#include <iostream>

using namespace std;

int main()
{
    int upperBound;

    // Since fibonacci is 0, 1, 1... load the first three numbers into the variables
    int number1 = 0, number2 = 1, currentFib = 1;

    cout << "Enter the upper bound for the fibonacci sequence: ";
    cin >> upperBound;

    // Check if the upper bound is valid (int greater than 0)
    if (upperBound <= 0 || cin.fail())
    {
        cout << "Invalid input.\n";
        // Exit the program
        return 0;
    }

    // Print the first number (it's always 0)
    cout << number1 << endl;

    // Repeat as long as the current number is less than the upper bound inputted
    while (currentFib < upperBound)
    {
        // Print the current number
        cout << currentFib << endl;
        // Now set the current number to the sum of the previous two numbers
        currentFib = number1 + number2;
        // Set the previous number to the current number
        number1 = number2;
        // Set the second number to the new current number
        number2 = currentFib;
    }

    return 0;
}