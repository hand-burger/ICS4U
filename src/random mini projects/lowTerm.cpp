#include <iostream>

using namespace std;

void lowTerm(double *fraction)
{
    // Reduce the fraction
    int gcd = fraction[0] * fraction[1];
    cout << "gcd: " << gcd << endl;
    fraction[0] /= gcd;
    fraction[1] /= gcd;
    fraction[0] *= 100;
    fraction[1] *= 100;

    // Print the reduced fraction
    cout << "The reduced fraction is: " << fraction[0] << "/" << fraction[1] << endl;
}

int main()
{
    double fraction[2] = {6, 12};
    lowTerm(fraction);
}