#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 5;
    // Preload vector with 1, 2, 3, 4, 5
    vector<int> riceBalls(N, 1);
    // Load vector with numbers 1, 2, 3, 4, 5
    for (size_t i = 0; i < N; ++i)
    {
        riceBalls[i] = i + 1;
    }

    for (size_t i = 0; i < N; i++)
    {
        N--;
        cout << riceBalls[i] << endl;
    }

    return 0;
}