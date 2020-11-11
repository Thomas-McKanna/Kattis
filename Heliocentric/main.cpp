#include <stdio.h>

using namespace std;

int main () {
    int e, m, count, i = 1;
    while (scanf("%d %d", &e, &m) != EOF) {
        count = 0;
        while (e != 0 || m != 0) {
            e = (e + 1) % 365;
            m = (m + 1) % 687;
            count++;
        }
        printf("Case %d: %d\n", i, count);
        i++;
    }

    return 0;
}
