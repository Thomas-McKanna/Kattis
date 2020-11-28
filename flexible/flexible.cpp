#include <stdio.h>
#include <cstring>

using namespace std;

int main() {
    int W, P, partitions[102], widths[102];
    memset(widths, 0, sizeof(widths));

    scanf("%d %d", &W, &P);

    for (int i = 0; i < P; i++) {
        scanf("%d", partitions + i + 1);
    }
    partitions[0] = 0;
    partitions[P + 1] = W;

    for (int i = 0; i <= P + 1; i++) {
        for (int j = i + 1; j <= P + 1; j++) {
            widths[partitions[j] - partitions[i]] = 1;
        }
    }

    for (int i = 1; i < 102; i++) {
        if (widths[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}