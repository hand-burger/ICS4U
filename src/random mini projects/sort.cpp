#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> numbers;
    cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    sort(numbers.begin(), numbers.end());

    cout << endl;

    for (auto i : numbers)
    {
        cout << i << endl;
    }

    return 0;
}