#include <stdio.h>

using namespace std;

int matrix[20][20];

int main() {
    int n;
    scanf("%d", &n);
    while (n != -1) {
        // read in matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            bool weak = true;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != k && matrix[i][j] == 1 && matrix[i][k] == 1 && matrix[j][k] == 1) {
                        weak = false;
                    }
                }
            }
            if (weak) {
                printf("%d ", i);
            } 
        }
        printf("\n");
        scanf("%d", &n);
    }

    return 0;
}
