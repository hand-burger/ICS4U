#include <iostream>

using namespace std;

int main()
{
    int upperBound;

    int a = 1, b = 1, currentFib = 1;

    cout << "Enter the upper bound for the fibonacci sequence: ";
    cin >> upperBound;

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