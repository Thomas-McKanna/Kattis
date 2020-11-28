#include <stdio.h>

using namespace std;

int g(int n);

int f(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    return f(n - 2) + 2 * g(n - 1);
}

int g(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return f(n - 1) + g(n - 2);
}

int main() {
    int n;

    scanf("%d", &n);
    while (n != -1) {
        printf("%d\n", f(n));
        scanf("%d", &n);
    }

    return 0;
}