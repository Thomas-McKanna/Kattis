#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<double, double> dd;

int main() {
    int n, l, w, pos, rad;
    dd intervals[10000];
    double half_rec_w;
    while (scanf("%d %d %d", &n, &l, &w) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &pos, &rad);
            // make sure that the rectangle covers width of strip
            if (w / 2.0 > rad) {
                intervals[i] = dd(999999, 999999 + 1);
            } else {
                half_rec_w = sqrt(pow(rad, 2) - pow(w, 2) / 4.0);
                intervals[i] = dd(pos - half_rec_w, pos + half_rec_w);
            }
        }

        sort(intervals, intervals + n);

        double covered = 0.0;
        int best_choice = 0, current = 0, ans = 0;
        while (covered < l && current < n) {
            // choose interval that will stretch farthest to the right
            while (intervals[current].first <= covered) {
                if (intervals[current].second > intervals[best_choice].second) {
                    best_choice = current;
                }
                current++;
            }
            // make sure that this "best choice" would not leave a gap
            if (intervals[best_choice].first > covered) {
                ans = -1;
                break;
            }
            covered = intervals[best_choice].second;
            ans++;
            best_choice = current;
        }

        printf("%d\n", ans);
    }

    return 0;
}