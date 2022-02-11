#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> first(n);
    vector<int> second(n);

    for (size_t i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        first[i] = num;
    }
    for (size_t i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        second[i] = num;
    }

    return 0;
}