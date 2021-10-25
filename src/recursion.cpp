#include <iostream>

using namespace std;

double factorialFinder(double x)
{
    // Base case
    if (x == 1)
    {
        return 1;
    }
    else
    {
        return x * factorialFinder(x - 1);
    }
}

int main()
{
    double x;
    cin >> x;
    cout << factorialFinder(x) << endl;
    return 0;
}