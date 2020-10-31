#include <stdio.h>
#include <cstring>

using namespace std;

int N, K, known[10], targets[10], possible[360];

void find_possible(int angle) {
    if (possible[angle]) return;
    possible[angle] = true;
    for (int i = 0; i < N; i++) {
        find_possible((angle + known[i]) % 360);
    }
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &known[i]);
    }

    for (int i = 0; i < K; i++) {
        scanf("%d", &targets[i]);
    }

    memset(possible, false, sizeof(possible));

    find_possible(0);

    for (int i = 0; i < K; i++) {
        if (possible[targets[i]]) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}