#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

struct point {
    double x, y;

    point(double first, double second) {
        x = first;
        y = second;
    }
};

int dist(point &first, point &second) {
    return round(sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2)));
}

int main()
{
    int n;
    cin >> n;

    vector<point> points;

    set<int> unvisited;

    vector<int> tour;
    tour.push_back(0);

    double temp_x, temp_y;
    for (int i = 0; i < n; i++) {
        cin >> temp_x >> temp_y;
        points.push_back(point(temp_x, temp_y));
    }

    for (int i = 1; i <= n - 1; i++) {
        unvisited.insert(i);
    }

    int source = 0;
    int best;
    for (int i = 1; i <= n - 1; i++) {
        best = -1;
        for (int j = 0; j <= n - 1; j++) {

            if (unvisited.find(j) != unvisited.end()
                &&  source != j
                    && (best == -1 || dist(points.at(source), points.at(j)) < dist(points.at(source), points.at(best)))) {
                best = j;
            }
            else {
            }
        }

        tour.push_back(best);
        unvisited.erase(best);
        source = best;
    }

    for (auto it : tour) {
        cout << it << endl;
    }

    return 0;
}
