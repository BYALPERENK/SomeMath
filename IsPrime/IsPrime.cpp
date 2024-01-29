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
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    long long int x;
    cout << "Which number is prime?" << endl;
    cin >> x;

    if (isPrime(x))
    {
        cout << "Yes, it's a prime." << endl;
    }
    else
    {
        cout << "No, it's not a prime." << endl;
    }
    auto finish = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(finish - start).count() << " microseconds\n";
}