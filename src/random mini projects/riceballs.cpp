#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; // Number of rice balls
    cin >> N;
    // Get space seperated size of rice balls
    vector<int> riceBalls;
    // Get rice balls vector
    for (size_t i = 0; i < N; ++i)
    {
        int riceBall;
        cin >> riceBall;
        riceBalls.push_back(riceBall);
    }

    int compares = N - 1;
    int largest = 0;

    // If two adjacent rice balls are the same, combine them and erase the second one
    // If two rice balls are seperated by one in between, combine them and erase the second and third one
    // Repeat as many times as possible

    while (true)
    {

        // For adjacent rice balls there are N - 1 compares
        // For seperated rice balls are there N - 2 compares

        // Loop over each compare of the array, [i] and [i + 1]
        for (size_t i = 0; i < compares; ++i)
        {
            // Compare if adjacent rice balls are the same
            if (riceBalls[i] == riceBalls[i + 1])
            {
                // Combine the two rice balls
                riceBalls[i] += riceBalls[i + 1];
                // Erase the second rice ball (i + 1)
                riceBalls.erase(riceBalls.begin() + i + 1);
                if (compares > 0)
                {
                    compares--;
                }
            }
        }
        // Loop over each seperated compare of the array, [i] and [i + 1] and [i + 2]
        for (size_t i = 0; i < compares - 1; ++i)
        {
            // Compare if seperated rice balls are the same
            if (riceBalls[i] == riceBalls[i + 2])
            {
                riceBalls[i] = riceBalls[i] + riceBalls[i + 1] + riceBalls[i + 2];
                // Erase the second rice ball (i + 1)
                riceBalls.erase(riceBalls.begin() + i + 1);
                // Erase the third rice ball (i + 2)
                riceBalls.erase(riceBalls.begin() + i + 2);
                compares -= 2;
            }
        }
        // Print the largest rice ball
        for (size_t i = 0; i < riceBalls.size(); ++i)
        {
            if (riceBalls[i] > largest)
            {
                largest = riceBalls[i];
            }
        }
        cout << largest << endl;
    }

    return 0;
}