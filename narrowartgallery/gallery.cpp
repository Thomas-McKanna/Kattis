#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int N, k, R[200][2];
int memo [200][3][201];
int INF = 9999999;

int opt(int i, int j, int k) {
    // Base cases
    if (k < 0) return -INF;
    if (i == 0) {
        if (k > 1) return -INF;
        if (k == 1) {
            if (j == 0) return R[0][1];
            if (j == 1) return R[0][0];
            if (j == 2) return max(R[0][1], R[0][0]);
        }
        if (k == 0) {
            return R[0][1] + R[0][0];
        }
    }

    if (memo[i][j][k] != -1) return memo[i][j][k];

    // Recursive cases
    int res = -INF;
    if (j == 0) {
        res = max(R[i][1] + opt(i - 1, 0, k - 1), 
                  R[i][1] + R[i][0] + opt(i - 1, 2, k));
    }
    if (j == 1) {
        res = max(R[i][0] + opt(i - 1, 1, k - 1),
                  R[i][1] + R[i][0] + opt(i - 1, 2, k));
    }
    if (j == 2) {
        res = max(R[i][1] + opt(i - 1, 0, k - 1),
                  R[i][0] + opt(i - 1, 1, k - 1));
        res = max(res, R[i][1] + R[i][0] + opt(i - 1, 2, k));
    }
    memo[i][j][k] = res;
    return res;
}

int main() {
    scanf("%d %d", &N, &k);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &R[i][0], &R[i][1]);
    }

    memset(memo, -1, sizeof(memo));
    printf("%d", opt(N - 1, 2, k));

    return 0;
}