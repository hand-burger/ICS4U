#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; // Number of rice balls
    cin >> N;
    // Get space seperated size of rice balls
    int riceBalls[N];
    // Initialize vector to hold riceballs
    vector<int> riceBallsVector;
    // Get rice balls vector
    for (int i = 0; i < N; ++i)
    {
        cin >> riceBalls[i];
        riceBallsVector.push_back(riceBalls[i]);
    }

    // Print rice balls vector
    for (int i = 0; i < riceBallsVector.size(); ++i)
    {
        cout << riceBallsVector[i] << " ";
    }

    int numberOfCompares = N - 1;

    bool adjacent = true;
    bool seperated = true;

    // If two adjacent rice balls are the same they can be combined
    // The new riceball occupies the position of the first riceball and the other is set to 0
    // If there are two same rice balls seperated by one in between, the three of them can be combined
    // The new riceball occupies the position of the first riceball and the other two are set to 0
    // These operations can be repeated as many times as possible
    // Do a while true and exit when there are no more combinations possible

    while (adjacent && seperated)
    {
        // Looping over each compare of the array, [i] and [i + 1]
        for (int i = 0; i < numberOfCompares; ++i)
        {
            // Compare, if adjacent rice balls are the same
            if (riceBallsVector[i] == riceBallsVector[i + 1])
            {
                // Found a match, combine the two rice balls
                // Add them together and set the second one to 0
                riceBallsVector[i] = riceBallsVector[i] + riceBallsVector[i + 1];
                // Erase the second rice ball
                riceBallsVector.erase(riceBallsVector.begin() + i + 1);
            }
            // else
            // {
            //     // If there are no more matches, set adjacent to false
            //     adjacent = false;
            // }
        }
        for (int i = 0; i < numberOfCompares - 1; ++i)
        {
            // Now compare the rice balls [i] and [i + 2]
            if (riceBallsVector[i] == riceBallsVector[i + 2])
            {
                // Found a match, combine the two rice balls
                // Add them together and set the second one to 0
                riceBallsVector[i] = riceBallsVector[i] + riceBallsVector[i + 1] + riceBallsVector[i + 2];
                // Erase the two other rice balls
                riceBallsVector.erase(riceBallsVector.begin() + i + 1);
                riceBallsVector.erase(riceBallsVector.begin() + i + 2);
            }
            // else
            // {
            //     // If there are no more matches, set seperated to false
            //     seperated = false;
            // }
        }
    }
    // Loop over the array and find the largest rice ball
    int largestRiceBall = 0;
    for (int i = 0; i < N; ++i)
    {
        if (riceBallsVector[i] > largestRiceBall)
        {
            largestRiceBall = riceBallsVector[i];
        }
    }
    cout << largestRiceBall << endl;
    return 0;
}