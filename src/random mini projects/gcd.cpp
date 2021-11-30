// {1, 2, 3, 4, 5}
// 1, 5
// {1}, {1, 5}
// 1

#include <iostream>

using namespace std;

int *min_max(int *inputArray, int size)
{
    int min = inputArray[0], max = inputArray[0];
    for (int i = 0; i < size; i++)
    {
        if (inputArray[i] > max)
        {
            max = inputArray[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (inputArray[i] < min)
        {
            min = inputArray[i];
        }
    }
    int *result = new int[2];
    result[0] = min;
    result[1] = max;
    return result;
}

// Recursive GCD
int gcd(int a, int b)
{
    // Base case
    if (b == 0)
    {
        return a;
    }
    // Recursive case
    return gcd(b, a % b);
}

int main()
{
    int inputArray[5] = {12, 21, 31, 41, 60};
    int size = (sizeof(inputArray) / sizeof(*inputArray));
    int *minMax;
    minMax = min_max(inputArray, size);
    int denom = gcd(minMax[0], minMax[1]);
    cout << "GCD: " << denom << endl;
}