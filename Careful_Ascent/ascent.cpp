#include <stdio.h>
#include <cstdlib>
#include <ctgmath>
#include <algorithm>

using namespace std;

#define EPS 1e-11

struct shield {
    int lbound, ubound;
    double factor;

    shield() {
        lbound = 0;
        ubound = 0;
        factor = 0.0;
    }

    shield(int l, int u, double f) {
        lbound = l;
        ubound = u;
        factor = f;
    }
};

bool shield_compare(const shield& a, const shield& b) {
    return a.lbound < b.lbound;
}

int ffx, ffy, num_shields, l, u;
double f;
shield shields[101];

bool can_surpass_firely_x(double speed, int ffx, int ffy) {
    double distance = 0.0;
    int ffy_copy = ffy;
    int i = 0;
    // find first shield above firefly
    while (ffy > shields[i].lbound && i < num_shields) i++;
    for (int j = 0; j < i; j++) {
        double vertical = min(ffy_copy, shields[j].ubound) - shields[j].lbound;
        distance += vertical * speed * shields[j].factor;
        ffy -= vertical;
    }
    distance += ffy * speed;
    return distance >= ffx;
}

int main() {
    scanf("%d %d", &ffx, &ffy);
    scanf("%d", &num_shields);

    int dir = ffx < 0 ? -1 : 1;
    ffx = abs(ffx);

    for (int i = 0; i < num_shields; i++) {
        scanf("%d %d %lf", &l, &u, &f);
        shields[i] = shield(l, u, f);
    }

    sort(shields, shields + num_shields, shield_compare);

    double hi = ffx, lo = 0.0, mid = 0.0, ans = 0.0;
    while (fabs(hi - lo) > EPS) {
        mid = (lo + hi) / 2.0;
        if (can_surpass_firely_x(mid, ffx, ffy)) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%.11lf\n", dir * ans);
}