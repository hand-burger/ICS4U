#include <iostream>

using namespace std;

int main()
{
    string firstString, secondString;
    cin >> firstString >> secondString;

    int asteriskCount = 0;

    // Loop over each character in the second string and see if it is in the first string
    // If it is, remove it from the first string

    for (size_t i = 0; i < secondString.length(); ++i)
    {
        if (secondString[i] == '*')
        {
            asteriskCount++;
        }
        for (size_t j = 0; j < firstString.length(); ++j)
        {
            if (secondString[i] == firstString[j])
            {
                firstString.erase(firstString.begin() + j);
            }
        }
    }

    // Now subtract the number of asterisks from the length of the first string
    // If the result is 0, the strings are anagrams
    // If the result is not 0, the strings are not anagrams

    int difference = firstString.length() - asteriskCount;

    if (difference <= 0)
    {
        cout << "A" << endl;
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}