#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }

    double min_percent = 1.0;
    for (int i = 1; i <= n; i++) {
        temp = q.top();
        if (temp > i) {
            cout << "impossible";
            return 0;
        } else if ((double) temp / i < min_percent) {
            min_percent = (double) temp / i;
        }
        q.pop();
    }

    cout << fixed << setprecision(7) << min_percent;
    return 0;
}
