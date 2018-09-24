#include <iostream>

using namespace std;

int main()
{
    int scores[5][4];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> scores[i][j];
        }
    }

    int sums[5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            sums[i] += scores[i][j];
        }
    }

    int winner = 1;
    int score = sums[0];
    for (int i = 1; i < 5; i++) {
        if (sums[i] > score) {
            score = sums[i];
            winner = i + 1;
        }
    }

    cout << winner << " " << score;

    return 0;
}
