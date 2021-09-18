#include <iostream>

using namespace std;

int main()
{
    string word;
    cout << "Enter your word: ";
    cin >> word;

    // Word to lower case, since otherwise Racecar would not be a palindrome but racecar would be
    for (auto &c : word)
    {
        c = tolower(c);
    }

    // Reverse the word
    string reversed(word.rbegin(), word.rend());

    // Then analyze
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
