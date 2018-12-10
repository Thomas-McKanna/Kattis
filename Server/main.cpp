#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    queue<int> q;

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }

    int sum = 0;
    int count = 0;
    while (sum <= t && !q.empty()) {
        if (q.front() + sum > t) {
            break;
        }
        sum += q.front();
        q.pop();
        count++;
    }

    cout << count;

    return 0;
}
