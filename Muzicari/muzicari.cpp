#include <stdio.h>
#include <cstring>
#include <unordered_map>

using namespace std;

int T, N, breaks[500], ans[500];

unordered_map<int, int> memo;

int get_memo_key(int m, int t1, int t2) {
    int key = 0;
    while (m != 0) {
        key = (key << 1) | (m & 1);
        m /= 2;
    }
    while (t1 != 0) {
        key = (key << 1) | (t1 & 1);
        t1 /= 2;
    }
    while (t2 != 0) {
        key = (key << 1) | (t2 & 1);
        t2 /= 2;
    }
    return key;
}

int dp(int m, int t1, int t2) {
    if (m < 0 && t1 >= 0 && t2 >= 0) return 1;
    if (ans[m] != -1) return -1;
    if (t1 < 0 || t2 < 0) return -1;
    if (breaks[m] > t1 && breaks[m] > t2) return -1;
    int key = get_memo_key(m, t1, t2);
    if (memo.find(key) != memo.end()) return memo[key];
    int choice1 = dp(m - 1, t1 - breaks[m], t2);
    int choice2 = dp(m - 1, t1, t2 - breaks[m]);
    if (choice1 == 1) ans[m] = t1 - breaks[m];
    else if (choice2 == 1) ans[m] = t2 - breaks[m];
    else return memo[key] = -1;
    return memo[key] = 1;
}

int main() {
    scanf("%d %d", &T, &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &breaks[i]);
    }

    memset(ans, -1, sizeof(ans));
    dp(N - 1, T, T);

    for (int i = 0; i < N - 1; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[N - 1]);

    return 0;
}