#include <stdio.h>
#include <algorithm>
#include <limits>

using namespace std;

int n, t, dist[1000], speed[1000];

bool can(double c) {
    double time = 0;
    double offset;
    for (int i = 0; i < n; i++) {
        offset = speed[i] + c;
        if (offset != 0)
            time += (double) dist[i] / offset;
    }
    return time <= t;
}

int main() {
    scanf("%d %d", &n, &t);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", dist + i, speed + i);
    }

    int min_reading = speed[0];
    for (int i = 1; i < n; i++) {
        if (speed[i] < min_reading) {
            min_reading = speed[i];
        }
    }

    double hi = 1e9;
    double lo = -min_reading;
    double mid = 0;
    for (int i = 0; i < 70; i++) {
        mid = (hi + lo) / 2;
        if (can(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%.8lf\n", hi);

    return 0;
}