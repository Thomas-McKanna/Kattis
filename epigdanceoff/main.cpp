#include <stdio.h>

using namespace std;

int N, M;
char board[2000][2000];

int main() {
    scanf("%d %d", &N, &M);
    char temp;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &board[j][i]);
        }
        scanf("%c", &temp); // newline
    }

    int answer = 0;
    bool all_blank;
    for (int i = 0; i < M; i++) {
        all_blank = true;
        for (int j = 0; j < N; j++) {
            if (board[i][j] != '_') all_blank = false;
        }
        if (all_blank) answer++;
    }

    printf("%d\n", answer + 1);

    return 0;
}
