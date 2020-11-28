#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    vector<pair<int, int>> corners;
    corners.push_back(pair<int, int>(x1, y1));
    corners.push_back(pair<int, int>(x2, y2));
    corners.push_back(pair<int, int>(x1, y2));
    corners.push_back(pair<int, int>(x2, y1));

    vector<double> distances;

    if (x >= x1 && x <= x2) {
        distances.push_back(abs(y1 - y));
        distances.push_back(abs(y2 - y));
    } else if (y >= y1 && y <= y2) {
        distances.push_back(abs(x1 - x));
        distances.push_back(abs(x2 - x));
    } else {
        for (auto it = corners.begin(); it != corners.end(); it++) {
            distances.push_back(dist(it->first, it->second, x, y));
        }
    }

    sort(distances.begin(), distances.end());

    cout << distances.at(0);

    return 0;
}
