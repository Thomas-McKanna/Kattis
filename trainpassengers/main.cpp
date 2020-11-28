#include <stdio.h>

using namespace std;

int main() {
    int C, n;
    scanf("%d %d", &C, &n);

    bool possible = true;
    int left, boarded, waited, num_on_train = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &left, &boarded, &waited);
        if (left > num_on_train) {
            possible = false;
            break;
        }
        num_on_train -= left;
        if (boarded + num_on_train > C) {
            possible = false;
            break;
        }
        num_on_train += boarded;
        if (C - num_on_train > 0 && waited > 0) {
            possible = false;
            break;
        }
    }

    if (num_on_train != 0 || waited > 0) {
        possible = false;
    }

    if (possible) printf("possible\n");
    else printf("impossible\n");

    return 0;
}
