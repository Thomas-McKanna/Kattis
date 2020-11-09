#include <stdio.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int t[N];
    double v[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %lf", &t[i], &v[i]);
    }

    double answer = 0.0;
    for (int i = 1; i < N; i++) {
        answer += (v[i] + v[i - 1]) * (t[i] - t[i - 1]) / 2000.0;
    }

    printf("%5lf\n", answer);

    return 0;
}
