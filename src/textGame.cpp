#include <iostream>
#include <fstream>
#include <unistd.h> // For sleep

using namespace std;

int main()
{
    string saveFile, saveText, readText;

    cout << "Enter name of previous save file or create a new one: ";
    cin >> saveFile;

    saveFile += ".txt";

    ifstream fin(saveFile);

    // Read file, for determining whether it exists or not.

    while (getline(fin, readText))
    {
        saveText += readText;
    }

    // If save file does not yet exist, create new save

    if (saveText == "")
    {
        cout << "Creating new save file " << saveFile << " . . .\n";
        ofstream fout(saveFile);
        fout << saveFile;
        cout << "File created\n";
    }

    // Read the new file

    ifstream newFin(saveFile);

    // Reset texts

    readText = "";
    saveText = "";

    // Read file

    while (getline(newFin, readText))
    {
        saveText += readText;
    }

    cout << saveText << endl;

    fin.close();

    return 0;
}