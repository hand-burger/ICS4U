#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Separate text for reading and using, readText reads each line to add to text
    string text, readText;

    // Open source.txt

    ifstream fin("source.txt");

    // Loop over each line to add to the whole text variable

    while (getline(fin, readText))
    {
        text += readText;
        text += " ";
    }

    // Print whole text from file

    cout << text << endl;

    // Loop over each character in text
    // If character is a letter, add or subtract 13 to the character's ASCII value
    // If character is not a letter, do nothing to the character's ASCII value
    for (size_t i = 0; i < text.length(); ++i)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            if (text[i] + 13 > 'z')
            {
                text[i] = text[i] + 13 - 26;
            }
            else
            {
                text[i] = text[i] + 13;
            }
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            if (text[i] + 13 > 'Z')
            {
                text[i] = text[i] + 13 - 26;
            }
            else
            {
                text[i] = text[i] + 13;
            }
        }
        else
        {
            text[i] = text[i];
        }
    }

    // Print rot13 text

    cout << text << endl;

    // Close file

    fin.close();

    return 0;
}