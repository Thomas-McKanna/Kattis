#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n, m, tasks[200000], intervals[200000];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", tasks + i);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", intervals + i);
    }

    sort(tasks, tasks + n, greater<int>());
    sort(intervals, intervals + m, greater<int>());

    int ans = 0;
    int t = 0, i = 0;
    while (t < n && i < m) {
        while (tasks[t] > intervals[i] && t < n) {
            t++;
        }
        if (t == n) break;
        ans++, t++, i++;
    }

    printf("%d\n", ans);

    return 0;
}