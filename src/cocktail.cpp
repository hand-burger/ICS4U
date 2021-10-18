#include <iostream>

using namespace std;

void cocktail(int inputArray[], int numElements)
{
    bool swapped;
    int temp;

    // Loop over each element, for each element loop up and down array
    for (int i = 0; i < numElements; i++)
    {
        // Loop up array
        // numElements - i - 1 because number of elements -current pos and -1 for the element it is on
        for (int j = i; j < numElements - i - 1; j++)
        {
            // If the current element is less than the next one, swap 'em
            if (inputArray[j] < inputArray[j + 1])
            {
                temp = inputArray[j];
                inputArray[j] = inputArray[j + 1];
                inputArray[j + 1] = temp;
                swapped = true;
            }
        }

        // Loop down array
        // numElements - i - 2 for number of elements -current pos and -2
        for (int j = numElements - i - 2; j > i; j--)
        {
            // If current element is more than the next one, swap 'em
            if (inputArray[j] > inputArray[j - 1])
            {
                temp = inputArray[j];
                inputArray[j] = inputArray[j - 1];
                inputArray[j - 1] = temp;
                swapped = true;
            }
        }
        // If no swaps occur, then it is done.
        if (!swapped)
        {
            break;
        }
    }
    // Print sorted array
    for (int i = 0; i < numElements; i++)
    {
        cout << inputArray[i] << " ";
    }
    cout << endl;
}

int main()
{
    int numElements;

    cout << "Enter the number of elements: ";
    cin >> numElements;
    int inputArray[numElements];

    for (int i = 0; i < numElements; i++)
    {
        // Enter one element for each loop
        cout << "Enter number " << i + 1 << ": " << endl;
        cin >> inputArray[i];
    }

    cocktail(inputArray, numElements);

    return 0;
}