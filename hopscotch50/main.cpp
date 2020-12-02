#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

int n, k, map[50][50];
vector<ii> locations[2500 + 1];
ii next_hop[50][50];

int dist(ii p1, ii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main () {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            locations[map[i][j]].push_back(ii(i, j));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            next_hop[i][j] = ii(-1, -1);
            if (map[i][j] == k) continue;
            int best = 9999999, hop_dist;
            for (int k = 0; k < locations[map[i][j] + 1].size(); k++) {
                hop_dist = dist(ii(i, j), locations[map[i][j] + 1][k]);
                if (hop_dist < best) {
                    best = hop_dist;
                    next_hop[i][j] = locations[map[i][j] + 1][k];
                }
            }
        }
    }

    int best = 999999;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                int curr = 1, total = 0, cx = i, cy = j;
                while (next_hop[cx][cy].first != -1) {
                    total += dist(ii(cx, cy), next_hop[cx][cy]);
                    cx = next_hop[cx][cy].first;
                    cy = next_hop[cx][cy].second;
                    curr++;
                }
                if (curr == k && total < best) best = total;
            }
        }
    }

    if (best == 999999) best = -1;
    printf("%d\n", best);

    return 0;
}