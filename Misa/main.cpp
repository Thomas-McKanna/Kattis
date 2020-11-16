#include <stdio.h>

using namespace std;

int R, S;
char map[50][50], discard;

int x_dir[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int y_dir[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int handshake_count() {
    int x, y, count = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (map[i][j] != 'o') continue;
            for (int k = 0; k < 8; k++) {
                x = i + x_dir[k];
                y = j + y_dir[k];
                if (0 <= x && x < R && 0 <= y && y < S && map[x][y] == 'o') {
                    count++;
                } 
            }
        }
    }
    return count / 2;
}

int main() {
    scanf("%d %d", &R, &S);
    scanf("%c", &discard);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            scanf("%c", &map[i][j]);
        }
        scanf("%c", &discard);
    }

    int max_handshakes = handshake_count();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (map[i][j] == '.') {
                // try mirko sitting here
                map[i][j] = 'o';
                int count = handshake_count();
                if (count > max_handshakes) {
                    max_handshakes = count;
                }
                // revert back to original before proceeding
                map[i][j] = '.';
            }
        }
    }

    printf("%d\n", max_handshakes);

    return 0;
}
