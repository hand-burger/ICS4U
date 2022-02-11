#include <iostream>
#include <vector>
#include <cmath> // for sqrt

using namespace std;

int main()
{
    // Generate the first 1000 prime numbers (2, 3, 5 . . . 7919)

    int numberOfPrimes = 1000;

    // Create a vector to hold the prime numbers
    vector<int> primeContainer;

    // The starting point for the prime number, since 2 is the first prime number
    int currentNumber = 2;

    // Loop until we have the number of primes we need (1000)
    while (primeContainer.size() < numberOfPrimes)
    {
        // Track if the current number is prime
        bool isPrime = true;

        // Loop through each divisor up to the square root of the current number, since divisors are smaller than the square root
        for (size_t i = 0; i < sqrt(primeContainer.size()); ++i)
        {   
            // If the current number is divisible by any number, it is not prime
            if (currentNumber % primeContainer[i] == 0)
            {
                // Set the flag to false
                isPrime = false;
            }
        }

        // If the current number is prime, add it to the prime container
        if (isPrime)
        {
            primeContainer.push_back(currentNumber);
        }

        // Increment the current number
        currentNumber++;
    }


    // Print the prime numbers
    for (size_t i = 0; i < 1000; ++i)
    {
        cout << primeContainer[i] << endl;
    }

    return 0;
}