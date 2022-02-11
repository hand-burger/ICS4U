#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> input(N);

    vector<int> ocurred(N);

    for (size_t i = 0; i < N; ++i)
    {
        ocurred[i] = 0;
    }

    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        input[i] = num;
    }

    // Loop over each number and find the two most common readings
    // With those two numbers subtract them and take the absolute value of the difference
    // If there is a tie breaker, take the biggest numbers

    // Double nested for loop, take the first number and then compare it to the rest of the array and count each occurrence

    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; j++){
            if (input[i] == input[j])
            {
                ocurred[i]++;
            }
        }
    }

    int hold;

    // Now loop over the ocurred vector and find the two highest ocurrances,
    // If there is a tie, loop back through the input array and find the highest number with that number of ocurrances

    for (size_t i = 0; i < N; ++i)
    {
        int highest1 = 0;
        if (ocurrances[i] > highest1)
        {
            highest1 = ocurrances[i];
            // temporarily set ocurrances i to 0 so it isn't analyzed
            hold = ocurrances[i];
            ocurrances[i] = 0;
        }
    }

    for (size_t i = 0; i < N; ++i)
    {
        int highest2 = 0;
        if (ocurrances[i] > highest 2)
        {
            highest2 = ocurrances[i];
            // I don't feel like finishing this.
        }
    }

    for (size_t i = 0; i < N; ++i)
    {
        cout << ocurred[i] << endl;
    }

    return 0;
}