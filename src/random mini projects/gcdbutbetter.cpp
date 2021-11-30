#include <iostream>

using namespace std;

// Recursive GCD function
int gcd(int a, int b)
{
    // Base case
    if (b == 0)
    {
        return a;
    }
    // Recursive case
    return (gcd(b, a % b));
}

int main()
{
    int inputArray[5] = {12, 21, 31, 41, 60};
    // Get min and max of the input array
    // Size of array is 20 bytes, size of each element is 4 bytes, 20/4 = 5 (number of elements)
    int arraySize = (sizeof(inputArray) / sizeof(inputArray[0]));
    int min = *min_element(inputArray, inputArray + arraySize);
    int max = *max_element(inputArray, inputArray + arraySize);
    // Get the GCD of the min and max
    int theGCD = gcd(min, max);
    // Print the GCD
    cout << "GCD: " << theGCD << endl;
    return 0;
}