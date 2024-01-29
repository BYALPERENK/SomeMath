#include <iostream>
#include <random>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846; //It's pee
const double RADIUS = 0.5; //r=0.5

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
    uniform_real_distribution<> dis(0.0, 2 * PI); //Generate a random float 0.0-2pee

    double totalLength = 0.0;

    for (long long i = 0; i < sample_count; ++i) {
        double theta1 = dis(gen);
        double x1 = RADIUS * cos(theta1);
        double y1 = RADIUS * sin(theta1);

        double theta2 = dis(gen);
        double x2 = RADIUS * cos(theta2);
        double y2 = RADIUS * sin(theta2);

        double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        totalLength += distance;
    }

    double averageDistance = totalLength / sample_count;

    cout << "Average distance: " << averageDistance;
}
