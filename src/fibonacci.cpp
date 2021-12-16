#include <iostream>

using namespace std;

int main()
{
    int upperBound;

    int a = 0, b = 1, currentFib = 1;

    cout << "Enter the upper bound for the fibonacci sequence: ";
    cin >> upperBound;

    // Check if the upper bound is valid
    if (upperBound <= 0 || cin.fail())
    {
        cout << "Invalid input.\n";
        // Exit the program
        return 0;
    }

    cout << a << endl;

    // Repeat as long as the current number is less than the upper bound inputted
    while (currentFib < upperBound)
    {
        cout << currentFib << endl;
        currentFib = a + b;
        a = b;
        b = currentFib;
    };

    return 0;
}