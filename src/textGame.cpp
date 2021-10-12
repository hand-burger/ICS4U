#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    string saveFile, saveText, readText;
    bool newFile;
    int xPos, yPos;
    float boardX, boardY;

    cout << "\n||||||||||||||||||||||||||||||||" << endl;
    cout << "||                            ||" << endl;
    cout << "|| WELCOME TO SHIT TEXT GAME! ||" << endl;
    cout << "||                            ||" << endl;
    cout << "||||||||||||||||||||||||||||||||" << endl;

    cout << "\nEnter the name of previous save file or create a new one: ";
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
        newFile = true;
        cout << "Creating new save file " << saveFile << " . . .\n";
        ofstream fout(saveFile);
        cout << "File created\n";
    }

    // Read the new file

    ifstream newFin(saveFile);

    // Reset texts

    readText = "";
    saveText = "";

    // Draw initial board

    boardX = 9;
    boardY = 9;

    // Get middle for starting pos

    if (newFile)
    {
        xPos = ceil(boardX / 2) - 1;
        yPos = ceil(boardY / 2) - 1;
    }
    else
    {
        getline(newFin, readText);
        xPos = stoi(readText);
        getline(newFin, readText);
        yPos = stoi(readText);
    }

    cout << endl;

    // Draw board

    for (int i = 0; i < boardY; i++)
    {
        for (int j = 0; j < boardX; j++)
        {
            // If on starting pos, draw XX.
            if (i == yPos && j == xPos)
            {
                cout << "|XX|";
            }
            else
            {
                cout << "|::|";
            }
        }
        cout << endl;
    }

        fin.close();

    return 0;
}