#include <stdio.h>

using namespace std;

int main() {
    int W, N;
    scanf("%d %d", &W, &N);
    int area = 0, w, l;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &w, &l);
        area += w * l;
    }
    printf("%d\n", area / W);
    return 0;
}
