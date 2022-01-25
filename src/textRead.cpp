#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // create array to store text
    string text[2315];
    // Open file
    ifstream fin("wordle-answers-alphabetical.txt");
    // Loop over each line to add to the whole text variable
    int i = 0;
    // Read each line
    while (getline(fin, text[i]))
    {
        i++;
    }
    // Print whole text from file
    // for (int i = 0; i < 2315; i++)
    // {
    //     cout << text[i] << endl;
    // }
    // Loop over each character in text
    // If the second character is a 's', print the word

    for (size_t i = 0; i < 2315; ++i)
    {
        if (text[i][1] == 's')
        {
            cout << text[i] << endl;
        }
    }

    return 0;
}