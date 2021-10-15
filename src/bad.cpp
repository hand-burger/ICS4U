#include <iostream>
#include <fstream>
#include <string>
#include <array>
// #include <Windows.h>
using namespace std;

bool win;
int turns = 0;
class status
{
public:
    int xval;
    int yval;
    array<bool, 5> inventory;
};

// Creating the character object within the status class
status character;

void start()
{
    win = false; // you have not won the game before starting it you funny guy hahahahahahahahahahaha... because you're funny.
    // introduction to game and controls
    cout << "Your adventure begins. The adventure to make a really good sandwich.\nYou must find the five ingredients scattered around your house!\nControls:\nn - move north\ne - move east\ns - move south\nw - move west\ng - grab\nu - use\nload - load save\n";
    cout << "\nPress enter to continue\n";
    cin.get();
}

// clears the screen because yes
// void clear()
// {
//     COORD topLeft = {0, 0};
//     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//     CONSOLE_SCREEN_BUFFER_INFO screen;
//     DWORD written;

//     GetConsoleScreenBufferInfo(console, &screen);
//     FillConsoleOutputCharacterA(
//         console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
//     FillConsoleOutputAttribute(
//         console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
//         screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
//     SetConsoleCursorPosition(console, topLeft);
// }

void grab(int x, int y)
{ // Let's you grab an item if it is in range
    if (x == -5 && y == 5)
    {
        cout << "You picked up the loaf of bread\n";
        character.inventory[0] = true;
    }
    else if (x == 3 && y == 2)
    {
        cout << "You picked up the package of bacon\n";
        character.inventory[1] = true;
    }
    else if (x == -4 && y == -4)
    {
        cout << "You picked up the mayonaise\n";
        character.inventory[2] = true;
    }
    else if (x == 1 && y == -3)
    {
        cout << "You picked up the lettuce\n";
        character.inventory[3] = true;
    }
    else if (x == 5 && y == -1)
    {
        cout << "You picked up the tomatoes\n";
        character.inventory[4] = true;
    }
}

void use(int x, int y)
{ // Let's you use an item if you are in the correct area
    if (x == 5 && y == -5 && character.inventory[0] == true && character.inventory[1] == true && character.inventory[2] == true && character.inventory[3] == true && character.inventory[4] == true)
    {
        cout << "You have made it to the kitchen, you combine the bread, bacon, lettuce, tomato and mayonaise to make the world's best blt\n";
        win = true;
    }
    else
    {
        cout << "You have nothing that can be used here\n";
    }
}

// handles loading
void load()
{
    string filename;
    cout << "What file do you want to load from?\n"; // Picking what file to load from
    cin >> filename;
    string value;
    ifstream file(filename + ".txt");
    if (file.is_open())
    {
        for (int i = 1; i <= 2; i++)
        {
            getline(file, value);
            if (i == 1)
            {
                character.xval = stoi(value); // x value
            }
            else if (i == 2)
            {
                character.yval = stoi(value); // y value
            }
            else if (i == 3)
            {
                character.inventory[i - 3] = stoi(value); // item 1
            }
            else if (i == 4)
            {
                character.inventory[i - 3] = stoi(value); // item 2
            }
            else if (i == 5)
            {
                character.inventory[i - 3] = stoi(value); // item 3
            }
            else if (i == 6)
            {
                character.inventory[i - 3] = stoi(value); // item 4
            }
            else if (i == 7)
            {
                character.inventory[i - 3] = stoi(value); // item 5
            }
        }
    }
    else
    {
        cout << "That file doesn't exist\n";
        load();
    }
    file.close();
}

// Checks for a wall, lock or map boundary
void wallcheck(string direc)
{
    if (character.yval > 5 && direc == "n")
    {
        character.yval--;
        cout << "You were unable to move further...\n";
    }
    else if (character.xval > 5 && direc == "e")
    {
        character.xval--;
        cout << "You were unable to move further...\n";
    }
    else if (character.yval < -5 && direc == "s")
    {
        character.yval++;
        cout << "You were unable to move further...\n";
    }
    else if (character.xval < -5 && direc == "w")
    {
        character.xval++;
        cout << "You were unable to move further...\n";
    }
}

// handles the moving
void move(string direction)
{
    // clear();
    if (direction == "n")
    {
        turns++;
        if (turns == 1)
        {
            cout << "You take a step, turns out your legs actually work. That's good to know.\n";
        }
        cout << "you moved north\n";
        character.yval++;
        wallcheck(direction);
    }
    else if (direction == "e")
    {
        turns++;
        if (turns == 1)
        {
            cout << "You take a step, turns out your legs actually work. That's good to know.\n";
        }
        cout << "you moved east\n";
        character.xval++;
        wallcheck(direction);
    }
    else if (direction == "s")
    {
        turns++;
        if (turns == 1)
        {
            cout << "You take a step, turns out your legs actually work. That's good to know.\n";
        }
        cout << "you moved south\n";
        character.yval--;
        wallcheck(direction);
    }
    else if (direction == "w")
    {
        turns++;
        if (turns == 1)
        {
            cout << "You take a step, turns out your legs actually work. That's good to know.\n";
        }
        cout << "you moved west\n";
        character.xval--;
        wallcheck(direction);
    }
    else if (direction == "u")
    {
        use(character.xval, character.yval);
    }
    else if (direction == "g")
    {
        grab(character.xval, character.yval);
    }
    else if (direction == "load")
    {
        load();
    }
}

// Gives the player a description of their environment
void spacedesc(int x, int y)
{
    cout << "You are at position (" << x << ", " << y << ")\n";
    if (x == 0 && y == 0)
    {
        cout << "It's the starting area (your living room), you started your adventure here.\n";
    }
    // Text outputs for when you're on the same tile as an item
    else if (x == -5 && y == 5 && character.inventory[0] == false)
    {
        cout << "There's a loaf of delicious and nutricious whole wheat bread on the floor. Remember, the whiter the bread, the sooner you're dead\n";
    }
    else if (x == 3 && y == 2 && character.inventory[1] == false)
    {
        cout << "There's some packaged bacon on the counter, or some bacon substitute if that's how you roll...\n";
    }
    else if (x == -4 && y == -4 && character.inventory[2] == false)
    {
        cout << "You see a perfectly good jar of mayo in your junk drawer. It's not the brand you like bu it'll do in a pinch\n";
    }
    else if (x == 1 && y == -3 && character.inventory[3] == false)
    {
        cout << "You can see a head of iceberg lettuce under the couch. What was this leafy green delicacy doing under such an odd furniture article?\n";
    }
    else if (x == 5 && y == -1 && character.inventory[4] == false)
    {
        cout << "Two ripe tomatoes are sitting on the windowsill. You've heard that they need a good view in order to grow, so this placement makes sense\n";
    }
    // Text outputs for when you're within one step of an item
    else if ((x == 1 && (y == -2 || y == -4) || y == -3 && (x == -0 || x == -2)) && character.inventory[3] == false)
    {
        cout << "There is ice all over the floor but no water. This is because the ice in question is pieces of iceberg lettuce, the head must be nearby\n";
    }
    else if ((x == -5 && y == 4 || x == -4 && y == 5) && character.inventory[0] == false)
    {
        cout << "The bread is close, you can sense its presence\n";
    }
    else if ((x == -4 && (y == -3 || y == -5) || y == -4 && (x == -3 || x == -5)) && character.inventory[2] == false)
    {
        cout << "The smell of mayo alerts you to its presence nearby\n";
    }
    else if ((x == 3 && (y == 1 || y == 3) || y == 2 && (x == 3 || x == 4)) && character.inventory[1] == false)
    {
        cout << "A primal extinct sparks up from within you, bacon is within one tile...\n";
    }
    else if ((x == 5 && (y == 0 || y == -2) || y == -1 && x == 4) && character.inventory[4] == false)
    {
        cout << "A red gleam hits your retina, the tomatoes are within one tile\n";
    }
    // Text outputs for random tiles with clues
    else if (x == 0 && y == 3)
    {
        cout << "There's a shopping list on the floor, it reads: bread, bacon, lettuce, tomato, mayo\n";
    }
    else if (x == 0 && y == 5)
    {
        cout << "You're at the back of your house, the bread pantry is west from here\n";
    }
    else if (x == 4 && y == 5)
    {
        cout << "In a drawer you find the architectural lans for your house, ou read that the base is a 10 x 10 square\n";
    }
    else if (x == -4 && y == 2)
    {
        cout << "A note reads: the condiment pantry is 6 paces south\n";
    }
    else if (x == -4 && y == -1)
    {
        cout << "You remember that this is an airbnb and that you have no idea where anything is. Guess you'll have to keep wandering\n";
    }
    else if (x == -2 && y == -1)
    {
        cout << "A map of the house reads the following: the kitchen lies in the farthest regions south and east\n";
    }
    else if (x == -1 && y == -3)
    {
        cout << "A thoght occurs in your mind: 'The bacon lies in the region of complete positivity'\n";
    }
    else if (x == 1 && y == -5)
    {
        cout << "A note on the wall reads: the tomatoes are exactly 5.65 tiles [N 45 E]\n";
    }
    else if (x == 5 && y == -3)
    {
        cout << "Another note reads: the mayo is in a double negative position (x,y) where x and y are the same thing.\n";
    }
    else if (x == 5 && y == 1)
    {
        cout << "You realize that you can acquire the ingredients in any order\n";
    }
    else if (x == -3 && y == 1)
    {
        cout << "You think to yourself: if I'm ever lost, I should retrace my steps and visit a different area\n";
    }
    else if (x == 5 && y == -5)
    {
        cout << "You are in the kitchen\n";
    }
}

// All functions go back to here
int main()
{
    start();
    character.xval = 0;
    character.yval = 0;
    character.inventory = {false, false, false, false, false};
    while (!win)
    {
        string action;
        spacedesc(character.xval, character.yval);
        cout << "Action: ";
        cin >> action;
        move(action);
        if (action == "q")
        { // quitting the game
            string sure;
            cout << "are you sure you want to quit?\nyes\nno\n";
            cin >> sure;
            if (sure == "no")
            {
                continue;
            }
            else if (sure == "yes")
            {
                string filename;
                cout << "what file do you want to save to?\n"; // picking what file to save to
                cin >> filename;
                ofstream file(filename + ".txt");

                file << character.xval << "\n"
                     << character.yval << '\n'; // loads position into the data
                for (int i = 0; i < 5; i++)
                { // loads character's inventory
                    file << character.inventory[i];
                    if (i != 4)
                    {
                        file << "\n";
                    }
                }
                file.close();
                break;
            }
        }
    }
    if (win)
    {
        cout << "You have completed the quest! Play again on another save file if you want\n";
    }
    system("pause");
    return 0;
}