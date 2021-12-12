#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *primes = new int[n];
    int *isPrime = new int[n];
    for (int i = 0; i < n; i++)
    {
        isPrime[i] = 1;
    }
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            primes[i] = i;
            for (int j = i * i; j < n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}