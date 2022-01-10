#include <iostream>

using namespace std;

int main()
{
    // Cocktail sort algorithm

    int numElements;

    cout << "Enter the number of elements: ";
    cin >> numElements;

    // Create an array of integers with the size of numElements
    int inputArray[numElements];

    for (size_t i = 0; i < numElements; ++i)
    {
        // Enter each element of the array
        cout << "Enter element " << i + 1 << ": ";
        cin >> inputArray[i];
    }

    int temp;

    // Loop up and down input array

    for (size_t i = 0; i < numElements - 1; ++i)
    {
        for (size_t j = 0; j < numElements - i - 1; ++j)
        {
            // If the element is greater than the next element, swap them
            if (inputArray[j] > inputArray[j + 1])
            {
                temp = inputArray[j];
                inputArray[j] = inputArray[j + 1];
                inputArray[j + 1] = temp;
            }
        }
    }

    // Print the output array
    cout << "Sorted array: ";
    for (size_t i = 0; i < numElements; ++i)
    {
        cout << inputArray[i] << " ";
    }

    cout << endl;

    return 0;
}