#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int a, d, asc_h[5001], asc_t[5001], dsc_h[5001], dsc_t[5001], mountain_h = 0;

bool monk_passed_same_spot(double time) {
    double monk_asc_h = 0.0, monk_dsc_h = 0.0;
    double t = 0;
    int i = 0;
    while (i < a && t < time) {
        monk_asc_h += min(
            (double) asc_h[i], 
            ((time - t) / asc_t[i]) * asc_h[i]
        );
        t += asc_t[i];
        i++;
    }
    t = 0;
    i = 0;
    while (i < d && t < time) {
        monk_dsc_h -= min(
            (double) dsc_h[i], 
            ((time - t) / dsc_t[i]) * dsc_h[i]
        );
        t += dsc_t[i];
        i++;
    }
    return (mountain_h + monk_dsc_h) <= monk_asc_h;
}

int main() {
    int temp;
    cin >> a >> d;

    for (int i = 0; i < a; i++) {
        cin >> temp;
        asc_h[i] = temp;
        cin >> temp;
        asc_t[i] = temp;
    }

    for (int i = 0; i < d; i++) {
        cin >> temp;
        dsc_h[i] = temp;
        cin >> temp;
        dsc_t[i] = temp;
    }

    for (int i = 0; i < a; i++) {
        mountain_h += asc_h[i];
    }

    double hi = 100 * 5000 + 1;
    double lo = 0.0;
    double mid;

    while (fabs(hi - lo) > 1e-9) {
        mid = (hi + lo) / 2.0;
        if (monk_passed_same_spot(mid))
            hi = mid;
        else
            lo = mid;
    }

    cout << setprecision(9) << fixed << hi << endl;

    return 0;
}