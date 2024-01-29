#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int main()
{
    long long sample_count;

    cout << "How many samples should be taken? ";

    if (!(cin >> sample_count) || sample_count <= 0) {
        cerr << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    random_device rd; //Seed
    mt19937 gen(rd()); //Mersenne Twister pseudo-random generator
    uniform_real_distribution<> dis(0.0, 1.0); //Generate a random float 0.0-1.0

    double totalLength = 0.0;

    for (long long i = 0; i < sample_count; ++i) {
        double x1 = dis(gen);
        double y1 = dis(gen);
        double x2 = dis(gen);
        double y2 = dis(gen);

        double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        totalLength += distance;
    }

    double averageDistance = totalLength / sample_count;

    cout << "Average distance: " << averageDistance << endl;

}


