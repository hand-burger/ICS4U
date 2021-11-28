#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int find_gcd(vector<int> const &nums)
{
    auto const r = minmax_element(nums[0], nums[-1]);
    return r.first;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << find_gcd(nums);
    return 0;
}