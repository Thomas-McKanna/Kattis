#include <stdio.h>
#include <algorithm>

using namespace std;

/*
* The solution is to compute the times for each problem, sort in increasing
* order, and then choose problems in the order.
*
* The trick is to use long long data type since A, B, C, and t0 can each be
* at most 10^6, and 10^6*10^6 will exceed 2^32.
*/

int main() {
    long long N, T, A, B, C, t[10000];
    scanf("%lld %lld %lld %lld %lld %lld", &N, &T, &A, &B, &C, &t[0]);

    for (int i = 1; i < N; i++) {
        t[i] = (A * t[i - 1] + B) % C + 1;
    }
    sort(t, t + N);

    long long ans = 0;
    int time_used = 0, i;
    for (i = 0; i < N; i++) {
        if (time_used + t[i] > T) break;
        time_used += t[i];
        ans = (ans + time_used) % 1000000007;
    }

    printf("%d %lld\n", i, ans);

    return 0;
}