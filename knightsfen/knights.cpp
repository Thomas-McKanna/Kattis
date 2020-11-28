#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

char board[5][5];

char goal[5][5] = {
    {'1', '1', '1', '1', '1'},
    {'0', '1', '1', '1', '1'},
    {'0', '0', ' ', '1', '1'},
    {'0', '0', '0', '0', '1'},
    {'0', '0', '0', '0', '0'}
};

int x_offsets[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
int y_offsets[8] = {-1, -2, 1, 2, -1, -2, 1, 2};

unordered_map<long, int> memo;

long get_memo_key(int depth) {
    long key = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == '0') {
                key = (key << 1) | 0;
                key = (key << 1) | 1; 
            }
            if (board[i][j] == '1') {
                key = (key << 1) | 1;
                key = (key << 1) | 0;
            }
            if (board[i][j] == ' ') {
                key = (key << 1) | 1;
                key = (key << 1) | 1;
            }
        }
    }
    while (depth != 0) {
        key = (key << 1) | (depth % 2);
        depth /= 2;
    }
    return key;
}

bool final_position() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] != goal[i][j]) 
                return false;
        }
    }
    return true;
}

int backtrack(int x, int y, int old_x, int old_y, int depth) {
    if (depth > 10) return depth;
    if (final_position()) return depth;

    long key = get_memo_key(depth);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int best = 9999;
    int new_x, new_y;
    for (int i = 0; i < 8; i++) {
        new_x = x + x_offsets[i];
        new_y = y + y_offsets[i];
        if (new_x == old_x && new_y == old_y) continue;
        if (0 <= new_x && new_x < 5 && 0 <= new_y && new_y < 5) {
            board[x][y] = board[new_x][new_y];
            board[new_x][new_y] = ' ';
            best = min(best, backtrack(new_x, new_y, x, y, depth + 1));
            board[new_x][new_y] = board[x][y];
            board[x][y] = ' ';
        }
    }
    return memo[key] = best;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string line;
    int start_x, start_y, ans;
    while (N--) {
        for (int i = 0; i < 5; i++) {
            getline(cin, line);
            for (int j = 0; j < 5; j++) {
                if (line[j] == ' ') {
                    start_x = i;
                    start_y = j;
                }
                board[i][j] = line[j];
            }
        }
        ans = backtrack(start_x, start_y, -1, -1, 0);
        if (ans > 10) {
            cout << "Unsolvable in less than 11 move(s)." << endl;
        } else {
            cout << "Solvable in " << ans << " move(s)." << endl;
        }
    }

    return 0;
}