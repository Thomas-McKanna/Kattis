#include <iostream>
#include <cstring>

using namespace std;

int N, M, ans = 0;
char map[1002][1002];

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

void color_sea(int x, int y) {
    map[x][y] = 'S';
    int new_x, new_y;
    for (int i = 0; i < 4; i++) {
        new_x = x + dir_x[i];
        new_y = y + dir_y[i];
        if (0 <= new_x && new_x < N + 2 & 0 <= new_y && new_y < M + 2) {
            if (map[new_x][new_y] == '0') color_sea(new_x, new_y);
        }
    }
}

void explore_land(int x, int y) {
    int new_x, new_y;
    for (int i = 0; i < 4; i++) {
        new_x = x + dir_x[i];
        new_y = y + dir_y[i];
        if (0 <= new_x && new_x < N + 2 & 0 <= new_y && new_y < M + 2) {
            if (map[new_x][new_y] == 'S') ans++;
        }
    }
    map[x][y] = 'L';
    for (int i = 0; i < 4; i++) {
        new_x = x + dir_x[i];
        new_y = y + dir_y[i];
        if (0 <= new_x && new_x < N + 2 & 0 <= new_y && new_y < M + 2) {
            if (map[new_x][new_y] == '1') explore_land(new_x, new_y);
        }
    }
}

int main() {
    cin >> N >> M;
    cin.ignore();

    memset(map, '0', sizeof(map));

    string line;
    for (int i = 1; i <= N; i++) {
        getline(cin, line);
        for (int j = 0; j < M; j++) {
            map[i][j+1] = line[j];
        }
    }

    color_sea(0, 0);

    

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < M + 1; j++) {
            if (map[i][j] == '1') explore_land(i, j);
        }
    }

    cout << ans << endl;

    return 0;
}