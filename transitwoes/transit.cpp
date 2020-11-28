#include <stdio.h>

using namespace std;

int main() {
    int s, t, n;
    scanf("%d %d %d", &s, &t, &n);

    int d[n+1];
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &d[i]);
    }

    int b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    s += d[0]; // walk to first bus stop
    for (int i = 0; i < n; i++) {
        s += c[i] % s; // wait for bus
        s += b[i]; // ride bus
        s += d[i+1]; // walk to next bus stop (or class if last iteration)
    }

    if (s <= t) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
