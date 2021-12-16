#include <iostream>
#include <fstream> // For files
#include <cmath>   // For position rounding

using namespace std;

void clearConsole()
{
    // Might not work on windows, idk.

    cout << "\033c";
}

void save(string saveFile, int pos[], bool inventory[])
{
    // Open file and write the x and y pos and the inventory
    ofstream file(saveFile);
    file << pos[0] << "\n";
    file << pos[1] << "\n";
    for (size_t i = 0; i < 5; ++i)
    {
        file << inventory[i];
        // If on the last line don't put a newline
        if (i != 4)
        {
            file << "\n";
        }
    }
    cout << "Progress saved to " << saveFile << endl;
}

void drawBoard(int boardY, int boardX, int pos[])
{
    // Take in the defined size of the board (Which can be modified and you already know the position of the objects scales to the size)
    // and draw the board, using the pos to mark current position with |XX|
    for (size_t i = 0; i < boardY; ++i)
    {
        for (size_t j = 0; j < boardX; ++j)
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
    // Get the direction and return it.

    cin >> direct;

    return direct;
}

void position(int pos[], int objects[5][2], bool inventory[])
{
    // For comparing position to objects
    string stringPos;
    string stringObj;

    // Print current position (x, y)
    cout << "(" << pos[0] << ", " << pos[1] << ")" << endl;

    // Get pos as string
    for (size_t i = 0; i < 2; ++i)
    {
        stringPos += to_string(pos[i]);
    }

    cout << endl;

    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 2; ++j)
        {
            // Get objects as string
            stringObj += to_string(objects[i][j]);
            j++;
            stringObj += to_string(objects[i][j]);

            // Compare pos as objs
            if (stringPos == stringObj)
            {
                // When a match is found, check which one and print it, oh and it it to the inventory
                if (i == 0 && !inventory[i])
                {
                    cout << "You found the key to unlock Don's dungeon.\n";
                    inventory[i] = true;
                }
                else if (i == 1 && !inventory[i])
                {
                    cout << "You found the key to unlock James' dungeon, he is forever grateful.\n";
                    inventory[i] = true;
                }
                else if (i == 2 && !inventory[i])
                {
                    cout << "You found the key to unlock Thor's dungeon, too bad he already picked the lock.\n";
                    inventory[i] = true;
                }
                else if (i == 3 && !inventory[i])
                {
                    cout << "You found the key to unlock Mark's dungeon, cool.\n";
                    inventory[i] = true;
                }
                else if (i == 4 && !inventory[i])
                {
                    cout << "You found the key to unlock Toms's dungeon, neat.\n";
                    inventory[i] = true;
                }
            }

            // Clear string obj after each loop or it'll just add it on
            stringObj = "";
        }
    }
}

int *move(char direct, int boardY, int boardX, int pos[], int objects[5][2], bool inventory[])
{
    // Take in the direction and change the position
    // Also has collision detection so it doesn't go out of bounds
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

    cout << endl;

    // After getting to change in position, draw the board again and check & compare position
    drawBoard(boardY, boardX, pos);
    position(pos, objects, inventory);

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
    bool inventory[5] = {false, false, false, false, false};

    cout << "\n|||||||||||||||||||||||||||||" << endl;
    cout << "||                         ||" << endl;
    cout << "||     DUNGEON FREEDOM     ||" << endl;
    cout << "||                         ||" << endl;
    cout << "|||||||||||||||||||||||||||||" << endl;

    cout << "\nEnter the name of previous save file or create a new one: ";
    cin >> saveFile;

    clearConsole();

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

    // Controls and story

    cout << "You and the boys decided to spend your guys night exploring an 'abandonned' asylum, what could go wrong?\n";
    cout << "While you're in this crazy house a group of humanoid figures capture you and your group, which isn't good.\n";
    cout << "They knock you out and lock you in dungeons, because of course there are dungeons in an asylum.\n";
    cout << "Obviously you have your lock picking set on you and you get out of your dungeon, and naturally the lock pick snaps in the keyhole.\n";
    cout << "So now the guys are trapped, forced to endure whatever skinwalker torture that is planned for them. . . Unless?\n\n";
    cout << "To move around, use the U, D, L & R keys to move Up, Down, Left & Right respectively.\n";
    cout << "Around the map there are 5 keys which you must collect to free each of your friends from their dungeons\n";
    cout << "If you want to quit at anytime, use the 's' key to save your progress.\n";

    // Read the new file

    ifstream newFin(saveFile);

    // Reset texts

    readText = "";
    saveText = "";

    // Size of board, can change

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
        ofstream newFin(saveFile);

        // Initialize new file with pos and inventory
        newFin << pos[0] << "\n";
        newFin << pos[1] << "\n";
        newFin << "0\n";
        newFin << "0\n";
        newFin << "0\n";
        newFin << "0\n";
        newFin << "0";
    }
    else
    {
        // When file already exists, read the pos and inventory
        getline(newFin, readText);
        pos[0] = stoi(readText);
        getline(newFin, readText);
        pos[1] = stoi(readText);
        for (size_t i = 0; i < 5; ++i)
        {
            getline(newFin, readText);
            if (readText == "0")
            {
                inventory[i] = false;
            }
            else if (readText == "1")
            {
                inventory[i] = true;
            }
        }
    }

    cout << endl;

    // Draw initial board

    drawBoard(boardY, boardX, pos);

    // Game loop

    while (!win)
    {
        // Get input direction

        direct = direction(direct);
        move(direct, boardY, boardX, pos, objects, inventory);

        // If save, save.

        if (direct == 's')
        {
            save(saveFile, pos, inventory);
            break;
        }
        // Check for win (loop over each inventory element and if any of them are false, break
        // otherwise check if the loop can complete which means all are true)
        for (size_t i = 0; i < 5; ++i)
        {
            if (!inventory[i])
            {
                break;
            }
            else if (i == 4)
            {
                win = true;
            }
        }
    }
    if (win)
    {
        save(saveFile, pos, inventory);
        cout << "\nNice work, you found all the keys and all your friends are free and safe, for now atleast. . .\n";
    }

    fin.close();

    return 0;
}