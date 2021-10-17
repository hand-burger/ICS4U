#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void clearConsole()
{
    printf("\033c");
}

void drawBoard(int boardY, int boardX, int yPos, int xPos)
{
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
    cout << endl;
}

char direction(char direct)
{
    cin >> direct;

    return direct;
}

void move(char direct, int boardY, int boardX, int yPos, int xPos)
{
    if (direct == 'U')
    {
        yPos--;
    }
    else if (direct == 'D')
    {
        yPos++;
    }
    else if (direct == 'L')
    {
        xPos--;
    }
    else if (direct == 'R')
    {
        xPos++;
    }

    // cout << xPos << yPos;

    clearConsole();

    cout << endl
         << endl;

    drawBoard(boardY, boardX, yPos, xPos);
}

int main()
{
    string saveFile, saveText, readText;
    char direct;
    bool newFile;
    bool win = false;
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

    // Size of board

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

    drawBoard(boardY, boardX, yPos, xPos);

    // Game loop

    while (!win)
    {
        // Get input direction

        direct = direction(direct);
        move(direct, boardY, boardX, yPos, xPos);

        if (direct == 's')
        {
            break;
        }
    }

    fin.close();

    return 0;
}