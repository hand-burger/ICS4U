#include <iostream>

using namespace std;

int main()
{
    string word;
    cout << "Enter your word: ";
    cin >> word;

    // Word to lower case, since palindromes are not case sensitive
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
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
