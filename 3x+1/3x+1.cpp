#include <iostream>
#include <ctime>

//It's my first code.

using namespace std;

//Do you know 3x+1 problem? If not, search "collatz problem".

int main()
{
    long long int a = 0;
    long long int lastNumber = 0;
    long long int b = 0;
    long long int c = 0;

    long long int ones = 0;
    long long int twos = 0;
    long long int threes = 0;
    long long int fours = 0;
    long long int fives = 0;
    long long int sixs = 0;
    long long int sevens = 0;
    long long int eights = 0;
    long long int nines = 0;
    long long int zeros = 0;


    cout << "Decide up to which number to calculate." << endl;
    cin >> lastNumber;
    cout << endl;
    clock_t start = clock();

    for (a = 2; a <= lastNumber; a++)
    {
        b = a;
        while (a > 1)
        {
            long long int d = a;
            while (a > 0)
            {
                c = a % 10;
                if (c == 0) { zeros++; }
                else if (c == 1) { ones++; }
                else if (c == 2) { twos++; }
                else if (c == 3) { threes++; }
                else if (c == 4) { fours++; }
                else if (c == 5) { fives++; }
                else if (c == 6) { sixs++; }
                else if (c == 7) { sevens++; }
                else if (c == 8) { eights++; }
                else if (c == 9) { nines++; }

                a = a / 10;
            }
            a = d;
            if (a % 2 == 0)
            {
                a = a / 2;
            }
            else
            {
                a = a * 3 + 1;
            }
        }
        a = b;
    };

    cout << zeros << " times 0" << endl;
    cout << ones << " times 1" << endl;
    cout << twos << " times 2" << endl;
    cout << threes << " times 3" << endl;
    cout << fours << " times 4" << endl;
    cout << fives << " times 5" << endl;
    cout << sixs << " times 6" << endl;
    cout << sevens << " times 7" << endl;
    cout << eights << " times 8" << endl;
    cout << nines << " times 9" << endl;

    double runTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    cout << runTime << endl;
}
/* PROPER CODE

#include <iostream>
#include <vector>
#include <ctime>

const int DIGIT_COUNT = 10;

long long CollatzSequence(long long number, std::vector<long long>& digitFrequency) {
    while (number > 1) {
        long long temp = number;
        while (temp > 0) {
            int digit = temp % 10;
            digitFrequency[digit]++;
            temp /= 10;
        }
        if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number = number * 3 + 1;
        }
    }
    return number;
}

int main() {
    long long limit;
    std::cout << "Decide up to which number to calculate: ";
    std::cin >> limit;

    std::vector<long long> digitFrequency(DIGIT_COUNT, 0);
    clock_t start = clock();

    for (long long i = 2; i <= limit; i++) {
        CollatzSequence(i, digitFrequency);
    }

    for (int i = 0; i < DIGIT_COUNT; i++) {
        std::cout << digitFrequency[i] << " times " << i << std::endl;
    }

    double executionTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
    std::cout << "Execution time: " << executionTime << " seconds" << std::endl;

    return 0;
}*/
