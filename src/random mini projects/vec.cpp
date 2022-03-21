#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    static const int arr[] = {1, 2, 3, 5, 4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    sort(v.rbegin(), v.rend());

    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}