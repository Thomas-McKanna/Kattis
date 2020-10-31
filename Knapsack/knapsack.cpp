#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

int C, n, values[2001], weights[2001], INF = 2e9;

int memo[2001][2001]; // [object][capacity]
ii previous[2001][2001];
bool take[2001][2001];
int sol[2001];

int knapsack(int i, int capacity) {
    if (capacity < 0) return -INF;
    if (i < 0) return 0;
    if (capacity == 0) return 0;

    if (memo[i][capacity] != -1) return memo[i][capacity];
    
    int do_take = values[i] + knapsack(i - 1, capacity - weights[i]);
    int dont_take = knapsack(i - 1, capacity);
    if (do_take >= dont_take) {
        previous[i][capacity] = ii(i - 1, capacity - weights[i]);
        take[i][capacity] = true;
        return memo[i][capacity] = do_take;
    } else {
        previous[i][capacity] = ii(i - 1, capacity);
        take[i][capacity] = false;
        return memo[i][capacity] = dont_take;
    }
}

int main() {
    int ans, k, i, c;
    ii temp;
    while (scanf("%d %d", &C, &n) != EOF) {
        memset(memo, -1, sizeof(memo));
        for (int j = 0; j < n; j++) {
            scanf("%d %d", &values[j], &weights[j]);
        }
        knapsack(n - 1, C);
        k = 0;
        i = n - 1;
        c = C;
        while (i >= 0 && c != 0) {
            if (take[i][c]) sol[k++] = i;
            temp = previous[i][c];
            i = temp.first;
            c = temp.second;
        }
        printf("%d\n", k);
        for (int j = 0; j < k; j++) {
            printf("%d ", sol[j]);
        }
        printf("\n");
    }

    return 0;
}