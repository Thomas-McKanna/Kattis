#include <stdio.h>
#include <unordered_map>

using namespace std;

int map[1000][1000];

// associate unique int ID with binary or decimal
// (used to determine what coloring originally was)
unordered_map<int, int> assignments; 

// unique ID to assign to different regions (will vary)
int color = 2;

int r, c;

int x_dir[4] = {1, 0, -1, 0};
int y_dir[4] = {0, 1, 0, -1}; 

void dfs_color(int target, int x, int y) {
    map[x][y] = color;
    int new_x, new_y;
    for (int i = 0; i < 4; i++) {
        new_x = x + x_dir[i];
        new_y = y + y_dir[i];
        if (new_x < 0 || new_x >= r || new_y < 0 || new_y >= c) continue;
        if (map[new_x][new_y] == target) {
            dfs_color(target, new_x, new_y);
        }
    }
}

int main() {
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 0) {
                assignments[color] = 0;
                dfs_color(0, i, j);
                color++;

            } else if (map[i][j] == 1) {
                assignments[color] = 1;
                dfs_color(1, i, j);
                color++;
            }
        }
    }

    int n, r1, c1, r2, c2;
    char color1, color2;
    scanf("%d", &n);

    while (n--) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        color1 = map[r1 - 1][c1 - 1];
        color2 = map[r2 - 1][c2 - 1];  
        if (color1 == color2) {
            if (assignments[color1] == 0) printf("binary\n");
            if (assignments[color1] == 1) printf("decimal\n");
        } else {
            printf("neither\n");
        }
    }

    return 0;
}