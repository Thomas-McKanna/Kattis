#include <stdio.h>
#include <cstring>

using namespace std;

int N, S, R, ans = 99999;
bool damaged_kayak[10], have_reserve[10];

void backtrack(int i) {
    if (i < 0) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (damaged_kayak[j]) count++;
        }
        if (count < ans) ans = count;
        return;
    }

    bool original;
    // do nothing
    backtrack(i - 1);

    if (have_reserve[i]) {
        // pass left
        if (i - 1 >= 0) {
            original = damaged_kayak[i - 1];
            damaged_kayak[i - 1] = false;
            backtrack(i - 1);
            damaged_kayak[i - 1] = original;
        }
        // keep reserve for self
        original = damaged_kayak[i];
        damaged_kayak[i] = false;
        backtrack(i - 1);
        damaged_kayak[i] = original;
        // pass right
        if (i + 1 < N) {
            original = damaged_kayak[i + 1];
            damaged_kayak[i + 1] = false;
            backtrack(i - 1);
            damaged_kayak[i + 1] = original;
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &S, &R);
    memset(damaged_kayak, false, sizeof(damaged_kayak));
    memset(have_reserve, false, sizeof(have_reserve));

    int temp;
    for (int i = 0; i < S; i++) {
        scanf("%d", &temp);
        damaged_kayak[temp - 1] = true;
    }
    for (int i = 0; i < R; i++) {
        scanf("%d", &temp);
        have_reserve[temp - 1] = true;
    }

    backtrack(N - 1);

    printf("%d\n", ans);

    return 0;
}