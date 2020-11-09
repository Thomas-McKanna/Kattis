#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, h, v;
    scanf("%d %d %d", &n, &h, &v);
    printf("%d\n", max(h, n - h) * max(v, n - v) * 4);
    return 0;
}
