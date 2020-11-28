#include <iostream>
#include <set>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int start, finish;

    set<int> first;
    cin >> start >> finish;
    for (int i = start + 1; i <= finish; i++) {
        first.insert(i);
    }

    set<int> second;
    cin >> start >> finish;
    for (int i = start + 1; i <= finish; i++) {
        second.insert(i);
    }

    set<int> third;
    cin >> start >> finish;
    for (int i = start + 1; i <= finish; i++) {
        third.insert(i);
    }

    int parked;
    int cost = 0;
    for (int i = 2; i <= 100; i++) {
        parked = 0;
        if (first.find(i) != first.end()) parked++;
        if (second.find(i) != second.end()) parked++;
        if (third.find(i) != third.end()) parked++;

        if (parked == 1) {
            cost += a;
        } else if (parked == 2) {
            cost += 2 * b;
        } else if (parked == 3) {
            cost += 3 * c;
        }
    }

    cout << cost;

    return 0;
}
