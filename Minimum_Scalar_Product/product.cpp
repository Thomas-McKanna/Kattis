#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

/*
The solution is to pair biggest number in list 1 with smallest number in list 2,
second biggest number in list 1 with second smallest number in list 2, and so
on for all remaining numbers.

Need to use long since 100000^2 > 4 billion.
*/

int main() {
    int T;
    scanf("%d", &T);

    long n, x[800], y[800], ans;
    for (int i = 1; i <= T; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%ld", &x[j]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%ld", &y[j]);
        }
        sort(x, x + n);
        sort(y, y + n, greater<long>());
        ans = 0;
        for (int j = 0; j < n; j++) {
            ans += x[j] * y[j];
        }
        printf("Case #%d: %ld\n", i, ans);
    }

    return 0;
}