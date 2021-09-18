#include <iostream>

using namespace std;

int main()
{
    string word;
    cout << "Enter your word: ";
    cin >> word;

    // Word to lower case
    for (auto &c : word)
    {
        c = tolower(c);
    }

    string reversed(word.rbegin(), word.rend());

    if (reversed == word)
    {
        cout << word << " is a palindrome.\n";
    }
    else
    {
        cout << word << " is not a palindrome.\n";
    }

    return 0;
}
