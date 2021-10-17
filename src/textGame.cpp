#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void clearConsole()
{
    // Might not work on windows

    cout << "\033c";
}

void drawBoard(int boardY, int boardX, int pos[])
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

void position(int pos[], int objects[5][2])
{
    cout << "(" << pos[0] << ", " << pos[1] << ")" << endl;

    string stringPos;
    string stringObj;

    for (int i = 0; i < 2; i++)
    {
        stringPos += to_string(pos[i]);
    }

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // cout << objects[i][j];
            stringObj += to_string(objects[i][j]);
            stringObj += to_string(objects[i][j + 1]);

            if (stringPos == stringObj)
            {
                cout << "You found it bozo";
            }

            stringObj = "";
            j++;
        }
        cout << " ";
    }

    cout << endl;
}

int *move(char direct, int boardY, int boardX, int pos[], int objects[5][2])
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

    drawBoard(boardY, boardX, pos);
    position(pos, objects);

    return pos;
}

int main()
{
    string saveFile, saveText, readText;
    char direct;
    bool newFile;
    bool win = false;
    int pos[2] = {};
    int objects[5][2] = {};
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

    // Size of board

    boardX = 9;
    boardY = 9;

    // Position of objects, relative to board size (comments for pos on 9x9 board)

    objects[0][0] = boardX - 2; // (7,1)
    objects[0][1] = boardY - (boardY - 1);
    objects[1][0] = ceil(boardX / 3) - 1; // (2, 5)
    objects[1][1] = ceil(boardY / 2);
    objects[2][0] = 0; // (0, 0)
    objects[2][1] = 0;
    objects[3][0] = ceil(sqrt(boardX)); // (3, 8)
    objects[3][1] = boardY - 1;
    objects[4][0] = ceil(boardX / 2); // (5, 5)
    objects[4][1] = ceil(boardY / 2);

    // Get middle for starting pos

    if (newFile)
    {
        pos[0] = ceil(boardX / 2) - 1;
        pos[1] = ceil(boardY / 2) - 1;
    }
    else
    {
        getline(newFin, readText);
        pos[0] = stoi(readText);
        getline(newFin, readText);
        pos[1] = stoi(readText);
    }

    cout << endl;

    // Draw initial board

    drawBoard(boardY, boardX, pos);

    // Game loop

    while (!win)
    {
        // Get input direction

        direct = direction(direct);
        move(direct, boardY, boardX, pos, objects);

        if (direct == 's')
        {
            break;
        }
    }

    fin.close();

    return 0;
}