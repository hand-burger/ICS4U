#include <iostream>
#include <map>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    // Separate text for reading and using, read reads each line to add to text

    string text, readText;

    // Open source.txt

    ifstream fin("source.txt");

    // Loop over each line to add to the whole text

    while (getline(fin, readText))
    {
        text += readText;
        text += " ";
    }

    // Print whole text from file

    cout << text << endl;

    // Map for each key and value

    map<string, string> rot_13;

    rot_13["a"] = "n";
    rot_13["b"] = "o";
    rot_13["c"] = "p";
    rot_13["d"] = "q";
    rot_13["e"] = "r";
    rot_13["f"] = "s";
    rot_13["g"] = "t";
    rot_13["h"] = "u";
    rot_13["i"] = "v";
    rot_13["j"] = "w";
    rot_13["k"] = "x";
    rot_13["l"] = "y";
    rot_13["m"] = "z";
    rot_13["n"] = "a";
    rot_13["o"] = "b";
    rot_13["p"] = "c";
    rot_13["q"] = "d";
    rot_13["r"] = "e";
    rot_13["s"] = "f";
    rot_13["t"] = "g";
    rot_13["u"] = "h";
    rot_13["v"] = "i";
    rot_13["w"] = "j";
    rot_13["x"] = "k";
    rot_13["y"] = "l";
    rot_13["z"] = "m";

    // Can't forget the capitals!

    rot_13["A"] = "N";
    rot_13["B"] = "O";
    rot_13["C"] = "P";
    rot_13["D"] = "Q";
    rot_13["E"] = "R";
    rot_13["F"] = "S";
    rot_13["G"] = "T";
    rot_13["H"] = "U";
    rot_13["I"] = "V";
    rot_13["J"] = "W";
    rot_13["K"] = "X";
    rot_13["L"] = "Y";
    rot_13["M"] = "Z";
    rot_13["N"] = "A";
    rot_13["O"] = "B";
    rot_13["P"] = "C";
    rot_13["Q"] = "D";
    rot_13["R"] = "E";
    rot_13["S"] = "F";
    rot_13["T"] = "G";
    rot_13["U"] = "H";
    rot_13["V"] = "I";
    rot_13["W"] = "K";
    rot_13["X"] = "K";
    rot_13["Y"] = "L";
    rot_13["Z"] = "M";

    // Iterate over each element of the map looking for pairs

    for (int i = 0; i <= text.length(); i++)
    {
        for (map<string, string>::iterator it = rot_13.begin(); it != rot_13.end(); it++)
        {
            string textString = string(1, text[i]);

            if (textString == it->first)
            {
                cout << it->second;
            }
            if (text[i] == ' ')
            {
                cout << ' ';
                break;
            }
        }
    }
    cout << endl;

    return 0;
}