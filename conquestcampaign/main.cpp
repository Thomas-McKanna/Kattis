#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void enqueue_neighbors(int r, int c, const pair<int, int> &p,
            queue<pair<int, int>> &q, vector<vector<bool>>& v) {
    // try top
    if (p.second > 0 && !v.at(p.first).at(p.second - 1)) {
        q.push(pair<int, int>(p.first, p.second - 1));
    }
    // try bot
    if (p.second < c - 1 && !v.at(p.first).at(p.second + 1)) {
        q.push(pair<int, int>(p.first, p.second + 1));
    }
    // try right
    if (p.first < r - 1 && !v.at(p.first + 1).at(p.second)) {
        q.push(pair<int, int>(p.first + 1, p.second));
    }
    // try left
    if (p.first > 0 && !v.at(p.first - 1).at(p.second)) {
        q.push(pair<int, int>(p.first - 1, p.second));
    }
}

int main()
{
    int r, c, n;
    cin >> r >> c >> n;

    queue<pair<int, int>> invade_next_1;
    queue<pair<int, int>> invade_next_2;
    vector<vector<bool>> visited(r, vector<bool>(c, false));

    pair<int, int> temp;
    for (int i = 0; i < n; i++) {
        cin >> temp.first >> temp.second;
        temp.first--;
        temp.second--;
        invade_next_1.push(temp);
    }

    int count = 0;
    int ans = 0;
    bool oscil = true; // true - 1, false - 2
    while (count < r * c) {
        if (oscil) {
            while (!invade_next_1.empty()) {
                temp = invade_next_1.front();
                if (!visited.at(temp.first).at(temp.second)) {
                    visited.at(temp.first).at(temp.second) = true;
                    enqueue_neighbors(r, c, temp, invade_next_2, visited);
                    count++;
                }
                invade_next_1.pop();
            }
        } else {
            while (!invade_next_2.empty()) {
                temp = invade_next_2.front();
                if (!visited.at(temp.first).at(temp.second)) {
                    visited.at(temp.first).at(temp.second) = true;
                    enqueue_neighbors(r, c, temp, invade_next_1, visited);
                    count++;
                }
                invade_next_2.pop();
            }
        }
        if (oscil) {
            oscil = false;
        } else {
            oscil = true;
        }
        ans++;
    }

    cout << ans;

    return 0;
}
