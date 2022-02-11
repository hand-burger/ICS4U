#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int total1 = 0;
    int total2 = 0;

    int k = 0;
    
    vector<int> team1(n);
    vector<int> team2(n);

    for (size_t i = 0; i < n; i++)
    {   
        int num;
        cin >> num;
        team1[i] = num;
    }
    for (size_t i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        team2[i] = num;
    }

    // Now loop over each score for each day and compare them, if they are the same than output i

    for (size_t i = 0; i < n; ++i)
    {

        total1 += team1[i];
        total2 += team2[i];

        if (total1 == total2)
        {
            k = i + 1;
        }
    }

    cout << k;

    return 0;
}