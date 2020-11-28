#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int n, papers[100000];

bool can(int c) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (papers[i] >= c) count++;
        else break;
    }
    return c > count;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", papers + i);
    }

    sort(papers, papers + n, greater<int>());

    int hi = 1e9;
    int lo = 0;
    int mid = 0;
    for (int i = 0; i < 60; i++) {
        mid = (hi + lo) / 2;
        if (can(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%d\n", lo);

    return 0;
}