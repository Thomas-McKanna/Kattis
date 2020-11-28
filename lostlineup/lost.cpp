#include <stdio.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int people[n + 1];
    people[1] = 1;

    int temp;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &temp);
        people[2 + temp] = i;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", people[i]);
    }
    printf("\n");

    return 0;
}
