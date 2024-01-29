#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

bool isPrime(long long int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    // To check through all numbers of the form 6k ± 1
    for (long long int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    long long last;
    cout << "Up to what number should i look for primes?" << endl;
    cin >> last;
    auto start = chrono::high_resolution_clock::now();
    vector <int> asal;
    asal.push_back(2);

    for (long long int i = 3; i < last; i = i + 2)
    {
        if (isPrime(i))
        {
            asal.push_back(i);
        }
    }
    cout << "I found " << asal.size() << " primes." << endl;
    auto finish = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(finish - start).count() << " microseconds\n";
    // If you want you can export to txt or print these primes.
}