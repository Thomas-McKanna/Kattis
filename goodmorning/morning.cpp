#include <stdio.h>
#include <set>
#include <cmath>

using namespace std;

set<int> nums;

int keyboard[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {-1, 0, -1} 
};

void generate_nums(int val, int x, int y) {
    if (val > 200) return;
    if (x == 3 && y == 1 && val == 0) return;
    // valid number, add to collection
    nums.insert(val);
    // go down
    if (x < 2 || (x < 3 && y != 0 && y != 2)) 
        generate_nums(val, x + 1, y);
    // go right
    if (x < 3 && y < 2) 
        generate_nums(val, x, y + 1);
    // same number again
    generate_nums(val * 10 + keyboard[x][y], x, y);
}

int main() {
    int T;
    scanf("%d", &T);

    generate_nums(0, 0, 0);

    int k, closest;
    while (T--) {
        scanf("%d", &k);
        closest = *nums.begin();
        for (auto n : nums) {
            if (abs(n - k) < abs(closest - k)) {
                closest = n;
            }
        }
        printf("%d\n", closest);
    }

    return 0;
}