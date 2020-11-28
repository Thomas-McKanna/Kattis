#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int P;
    scanf("%d", &P);

    int dataset, n[12];
    while (P--) {
        scanf("%d", &dataset);
        for (int i = 0; i < 12; i++) {
            scanf("%d", &n[i]);
        }
        int count = 0, smallest;
        for (int i = 1; i < 11; i++) {
            for (int j = 1; j < 12 - i; j++) {
                smallest = *min_element(n + j, n + j + i);
                if (smallest > n[j - 1] && smallest > n[j + i]) {
                    count++;
                }
            }
        }
        printf("%d %d\n", dataset, count);
    }

    return 0;
}