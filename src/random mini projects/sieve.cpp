#include <iostream>

using namespace std;

int main()
{
    int max;
    cout << "Enter the maximum number: ";
    cin >> max;

    // Make an array of size max to hold the prime numbers
    int *primes = new int[max];
    // Make another array to hold the state of the numbers (prime (true) or composite (false))
    bool *is_prime = new bool[max];
    // Set all the initial values to true
    for (int i = 0; i < max; i++)
    {
        is_prime[i] = true;
    }
    // Loop through each value from min to max
    for (int i = 2; i < max; i++)
    {
        // If the current number is prime, add it to the array of primes
        if (is_prime[i])
        {
            // Add the current number to the array of primes
            primes[i] = i;
            // Loop through all the multiples of i from i*i to max
            for (int j = i * i; j < max; j += i)
            {
                // If the current number is composite, set it to false
                is_prime[j] = false;
            }
        }
    }
    // Print the primes
    for (int i = 2; i < max; i++)
    {
        if (is_prime[i])
        {
            cout << primes[i] << " ";
        }
    }
    cout << endl;

    return 0;
}