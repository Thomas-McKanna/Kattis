#include <stdio.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;

// https://cpistoohard.blogspot.com/2018/09/bank-queue-kattis.html?zx=b217803a781bff14
// Sort by deposit amounts, in decreasing order. Place the customer with the 
// highest deposit as far as they can be placed in the queue. If the place is 
// occupied, keep trying to place them earlier until an open spot is found, or
// the candidate is discarding since there is no more room.
int main() {
    int N, T, c, t, queue[10000];
    pi people[10000];

    scanf("%d %d", &N, &T);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &c, &t);
        people[i] = pi(-c, t);
    }

    sort(people, people + N);

    int ans = 0;
    memset(queue, -1, sizeof(queue));
    for (int i = 0; i < N; i++) {
        c = -people[i].first;
        t = people[i].second;
        for (int j = t; j >= 0; j--) {
            if (queue[j] == -1) {
                queue[j] = 1;
                ans += c;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
