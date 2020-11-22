#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> vp;

int main() {
    int N;
    scanf("%d", &N);

    vp platforms;
    while (N--) {
        int Y, X1, X2;
        scanf("%d %d %d", &Y, &X1, &X2);
        platforms.push_back(iii(Y, ii(X1, X2)));
    }

    sort(platforms.begin(), platforms.end());

    // height of highest platform at position
    int h[10000];
    memset(h, 0, sizeof(h));

    int answer = 0;
    for (int i = 0; i < platforms.size(); i++) {
        iii platform = platforms[i];
        int Y = platform.first;
        ii bounds = platform.second;
        answer += Y - h[bounds.first] + Y - h[bounds.second - 1];
        for (int j = bounds.first; j < bounds.second; j++) {
            h[j] = Y;
        }
    }

    printf("%d\n", answer);

    return 0;
}