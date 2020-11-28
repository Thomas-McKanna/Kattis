#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> days;

    int start, finish;
    for (int i = 0; i < n; i++) {
        cin >> start >> finish;
        for (int j = start; j <= finish; j++) {
            if (days.find(j) == days.end()) {
                days.insert(j);
            }
        }
    }

    cout << days.size();

    return 0;
}
