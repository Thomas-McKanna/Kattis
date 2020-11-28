#include <stdio.h>
#include <cmath>

using namespace std;

int n;
int s[50];

double group_score(int leave_out) {
    double sum = 0.0;
    bool past_left_out = false;
    for (int i = 0; i < n; i++) {
        if (i != leave_out) {
            int power = past_left_out ? i - 1 : i;
            sum += s[i] * pow(4.0/5, power);
        } else {
            past_left_out = true;
        }
    }
    return sum * (1.0/5);
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    printf("%6lf\n", group_score(-1));

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += group_score(i);
    }
    printf("%6lf\n", sum / n);

    return 0;
}
