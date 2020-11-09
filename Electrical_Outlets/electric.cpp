#include <stdio.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int k;
    while (N--) {
        scanf("%d", &k);
        int total = 0, current;
        for (int i = 0; i < k; i++) {
            scanf("%d", &current);
            total += current - 1;
        }
        printf("%d\n", total + 1);
    }

    return 0;
}
