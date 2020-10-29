#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n, cost[30000], best_health = 0, best_potency = 0;
double b, health[30000], potency[30000];

double efficacy(double x, int i, int j) {
    double h1 = (b * x * health[i]) / cost[i];
    double h2 = (b * (1 - x) * health[j]) / cost[j];
    double p1 = (b * x * potency[i]) / cost[i];
    double p2 = (b * (1 - x) * potency[j]) / cost[j];
    return (h1 + h2) * (p1 + p2);
}

int main() {  
    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        cin >> cost[i] >> health[i] >> potency[i];
    }

    double max_efficacy = 0;

    for (int i = 0; i < n; i++) {
        double current =  (b * health[i] / cost[i]) * (b * potency[i] / cost[i]);
        if (current > max_efficacy) max_efficacy = current;
    }
    
    for (int i = 1; i < n; i++) {
        if (health[i] / cost[i] > health[best_health] / cost[best_health]) {
            best_health = i;
        }
        if (potency[i] / cost[i] > potency[best_potency] / cost[best_potency]) {
            best_potency = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != best_health) {
            for (int j = 0; j < 1000; j++) {
                double current = efficacy(j / 1000.0, best_health, i);
                if (current > max_efficacy) max_efficacy = current;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != best_potency) {
            for (int j = 0; j < 1000; j++) {
                double current = efficacy(j / 1000.0, best_potency, i);
                if (current > max_efficacy) max_efficacy = current;
            }
        }
    }

    cout << setprecision(5) << fixed << max_efficacy << endl;

    return 0;
}