#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    // Get number of test cases
    int k;
    cin >> k;

    int n, temp, dvd_num;
    list<int> ordering;
    for (int i = 0; i < k; i++) {
        ordering.clear();
        cin >> n;
        // Get the original order of dvds (from bottom of stack to top)
        for (int j = 0; j < n; j++) {
            cin >> temp;
            ordering.push_back(temp);
        }
        // Calculate how many are "in order"
        dvd_num = 1;
        for (auto it = ordering.begin(); it != ordering.end(); it++) {
            if (*it == dvd_num) {
                dvd_num++;
            }
        }
        // Answer is total number of dvds minus how many were already "in order"
        cout << n - dvd_num + 1 << endl;
    }

    return 0;
}