#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int C[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }

    sort(C, C + N, greater<int>());

    int answer = 0;
    for (int i = 0; i < N / 3; i++) {
        answer += C[3 * i] + C[3 * i + 1];
    }

    for (int i = (N / 3) * 3; i < N; i++) {
        answer += C[i];
    }

    printf("%d\n", answer);

    return 0;
}
