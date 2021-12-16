#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    // Load values 1 to 10 into the vector
    for (int i = 1; i <= 10; ++i)
    {
        vec.push_back(i);
    }
    // Erase the third element in the vector and print the vector
    vec.erase(vec.begin() + 2);
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    return 0;
}