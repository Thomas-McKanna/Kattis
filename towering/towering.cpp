#include <stdio.h>

using namespace std;

int main() {
    int h1, h2, boxes[6];
    
    for (int i = 0; i < 6; i++) {
        scanf("%d", boxes + i);
    }
    scanf("%d %d", &h1, &h2);

    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 6; b++) {
            for (int c = 0; c < 6; c++) {
                for (int d = 0; d < 6; d++) {
                    for (int e = 0; e < 6; e++) {
                        for (int f = 0; f < 6; f++) {
                            if (a != b && a != c && a != d && a != e && a != f
                                && b != c && b != d && b != e && b != f
                                && c != d && c != e && c != f
                                && d != e && d != f
                                && e != f
                                && boxes[a] >= boxes[b] 
                                && boxes[b] >= boxes[c] 
                                && boxes[d] >= boxes[e]
                                && boxes[e] >= boxes[f]
                                && boxes[a] + boxes[b] + boxes[c] == h1
                                && boxes[d] + boxes[e] + boxes[f] == h2) {
                                printf("%d %d %d %d %d %d\n", boxes[a], boxes[b], boxes[c], boxes[d], boxes[e], boxes[f]);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}