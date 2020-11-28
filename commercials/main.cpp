#include <stdio.h>

using namespace std;

// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

int main() {
    int N, P;
    scanf("%d %d", &N, &P);
    int current, max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &current);
        max_ending_here += current - P;
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }

    printf("%d\n", max_so_far);

    return 0;
}
