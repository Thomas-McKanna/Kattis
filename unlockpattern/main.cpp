#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    vector<pair<int, int>> path(9);

    int pos;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> pos;
            path.at(pos - 1) = pair<int, int>(i, j);
        }
    }

    double dist = 0.0;
    for (int i = 1; i < 9; i++) {
        dist += sqrt(pow(path.at(i).first - path.at(i - 1).first, 2)
             + pow(path.at(i).second - path.at(i - 1).second, 2));
    }

    cout << fixed << setprecision(10) << dist;

    return 0;
}
