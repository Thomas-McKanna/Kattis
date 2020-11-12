#include <stdio.h>

using namespace std;

bool RED = true;
bool GREEN = false;

int N, L;
int D[100], R[100], G[100], light_state[100], counts[100];
void increment_time() {
    for (int i = 0; i < N; i++) {
        counts[i]--;
        if (counts[i] == 0) {
            light_state[i] = !light_state[i];
            if (light_state[i] == GREEN) {
                counts[i] = G[i];
            } else {
                counts[i] = R[i];
            }
        }
    }
}

int main() { 
    scanf("%d %d", &N, &L);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &D[i], &R[i], &G[i]);
        light_state[i] = RED;
        counts[i] = R[i];
    }

    int current = 0, d;
    for (int i = 0; i < N; i++) {
        if (i == 0) d = D[0];
        else d = D[i] - D[i - 1];
        for (int j = 0; j < d; j++) {
            current++;
            increment_time();
        }
        while (light_state[i] != GREEN) {
            current++;
            increment_time();
        }
    }
    printf("%d\n", current + (L - D[N - 1]));

    return 0;
}