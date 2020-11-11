#include <stdio.h>

using namespace std;

char board[7][7];

int skip_dir_x[4] = {0, 1, 0, -1};
int skip_dir_y[4] = {1, 0, -1, 0};
int empty_dir_x[4] = {0, 2, 0, -2};
int empty_dir_y[4] = {2, 0, -2, 0};

int main() {
    char temp;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            scanf("%c", &temp);
            if (temp == ' ') {
                board[i][j] = 'x';
            } else {
                board[i][j] = temp;
            }
        }
        scanf("%c", &temp); // newline
    }

    int skip_x, skip_y, empty_x, empty_y, answer = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 'o') {
                for (int k = 0; k < 4; k++) {
                    skip_x = skip_dir_x[k] + i;
                    skip_y = skip_dir_y[k] + j;
                    empty_x = empty_dir_x[k] + i;
                    empty_y = empty_dir_y[k] + j;
                    if (0 <= empty_x && empty_x < 7 && 0 <= empty_y && empty_y < 7 && board[empty_x][empty_y] == '.' && board[skip_x][skip_y] == 'o') {
                        answer++;
                    }
                }
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}