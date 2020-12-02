#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

int n, k, map[50][50], best = 9999999;
vector<ii> locations[2500 + 1];
ii next_hop[50][50];

int dist(ii p1, ii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void bt(int i, ii from, int total) {
    if (i == k + 1 && total < best) best = total;
    if (total > best) return;
    for (int j = 0; j < locations[i].size(); j++) {
        int added_dist = 0;
        if (i != 1) added_dist = dist(from, locations[i][j]);
        bt(i + 1, locations[i][j], total + added_dist);
    }
}

int main () {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            locations[map[i][j]].push_back(ii(i, j));
        }
    }

    bt(1, ii(-1, -1), 0);

    if (best == 9999999) best = -1;
    printf("%d\n", best);

    return 0;
}