#include <iostream>

using namespace std;

int main()
{
    int inputArray[5] = {12, 21, 31, 41, 60};
    cout << sizeof(inputArray) << endl;
    for (size_t i = 0; i < 5; i++)
    {
        // size of int is 4 bytes
        // size of array is 20 bytes
        // 20/4 = 5
        cout << sizeof(inputArray[i]) << endl;
    }
    return 0;
}