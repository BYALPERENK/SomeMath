#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    vector<int> primesVec;
    vector<int> primesCountsVec;
    long long i;
    cout << "Enter a number to be prime factorized: ";
    cin >> i;

    if (i <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    if (i % 2 == 0)
    {
        primesVec.push_back(2);
        int count_2 = 0;
        while (i % 2 == 0)
        {
            i = i / 2;
            ++count_2;
        }
        primesCountsVec.push_back(count_2);
    }

    for (int j = 3; j <= sqrt(i); j = j + 2)
    {
        if (i % j == 0)
        {
            primesVec.push_back(j);
            int counter = 0;
            while (i % j == 0)
            {
                i = i / j;
                ++counter;
            }
            primesCountsVec.push_back(counter);
        }
    }

    if (2 < i)
    {
        primesVec.push_back(i);
        primesCountsVec.push_back(1);
    }
    for (int i = 0; i < primesVec.size(); i++)
    {
        cout << primesVec[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < primesCountsVec.size(); i++)
    {
        cout << primesCountsVec[i] << " ";
    }
}

