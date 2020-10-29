#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int T, N, ans[500];
    ii  breaks[500];

    scanf("%d %d", &T, &N);

    int temp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        breaks[i] = ii(temp, i);
    }

    sort(breaks, breaks + N);

    int t1 = T, t2 = T;
    int i = 0, j = N - 1;
    bool turn = true;
    while (i <= j) {
        if (i == j) {
            if (breaks[i].first <= t1) {
                ans[breaks[i].second] = t1 - breaks[i].first;
            }
            ans[breaks[i].second] = t2 - breaks[i].first;
            break;
        }
        if (turn) {
            t1 = t1 - breaks[i].first;
            ans[breaks[i].second] = t1;
            t1 = t1 - breaks[j].first;
            ans[breaks[j].second] = t1;
        } else {
            t2 = t2 - breaks[i].first;
            ans[breaks[i].second] = t2;
            t2 = t2 - breaks[j].first;
            ans[breaks[j].second] = t2;
        }
        i++;
        j--;
        turn = !turn;
    }

    for (int i = 0; i < N - 1; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[N - 1]);

    return 0;
}