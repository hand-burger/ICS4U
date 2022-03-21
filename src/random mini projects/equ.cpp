#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    // make an enumerated class for colors

    enum class Color { red, green, blue };

    // make a vector of colors

    vector<Color> Colors;

    // add colors to the vector

    Colors.push_back(Color::red);

    Colors.push_back(Color::green);

    Colors.push_back(Color::blue);

    // print the colors

    for (size_t i = 0; i < Colors.size(); i++)
    {
        if (Colors[i] == 0)
        {
            cout << "red" << endl;
        }
        
    }

    return 0;
}