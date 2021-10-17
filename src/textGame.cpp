#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void clearConsole()
{
    printf("\033c");
}

void drawBoard(int boardY, int boardX, int yPos, int xPos, int pos[])
{
    for (int i = 0; i < boardY; i++)
    {
        for (int j = 0; j < boardX; j++)
        {
            // If on starting pos, draw XX.
            if (i == pos[1] && j == pos[0])
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

int *move(char direct, int boardY, int boardX, int yPos, int xPos, int pos[])
{
    if (direct == 'U' && pos[1] > 0)
    {
        pos[1]--;
    }
    else if (direct == 'D' && pos[1] < boardY - 1)
    {
        pos[1]++;
    }
    else if (direct == 'L' && pos[0] > 0)
    {
        pos[0]--;
    }
    else if (direct == 'R' && pos[0] < boardX - 1)
    {
        pos[0]++;
    }

    clearConsole();

    cout << pos[0] << pos[1];

    cout << endl
         << endl;

    drawBoard(boardY, boardX, yPos, xPos, pos);

    return pos;
}

int main()
{
    string saveFile, saveText, readText;
    char direct;
    bool newFile;
    bool win = false;
    int xPos, yPos;
    int pos[2] = {};
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
        pos[0] = ceil(boardX / 2) - 1;
        xPos = ceil(boardX / 2) - 1;
        pos[1] = ceil(boardY / 2) - 1;
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

    drawBoard(boardY, boardX, yPos, xPos, pos);

    // Game loop

    while (!win)
    {
        // Get input direction

        direct = direction(direct);
        move(direct, boardY, boardX, yPos, xPos, pos);

        if (direct == 's')
        {
            break;
        }
    }

    fin.close();

    return 0;
}