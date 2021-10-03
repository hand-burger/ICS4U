#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string text, readText;

    ifstream fin("source.txt");

    while (getline(fin, readText))
    {
        text += readText;
        text += " ";
    }

    cout << text << endl;

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

    string a = "a";

    // map<string, string>::iterator it = rot_13.find(a);
    // cout << "key found " << it->second << endl;

    for (map<string, string>::iterator it = rot_13.begin(); it != rot_13.end(); it++)
    {
        // cout << it->first << " == " << it->second << endl;

        for (int i = 0; i <= text.length(); i++)
        {
            // cout << text[i] << endl;
            // cout << it->first << endl;
            string textString = string(1, text[i]);

            if (textString == it->first)
            {
                cout << it->second;
            }
            // cout << it->first << it->second << endl;
        }
    }

    return 0;
}