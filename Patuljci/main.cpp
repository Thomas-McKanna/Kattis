#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
    vector<int> v(9);

    unordered_map<int, int> m;

    int temp;
    for (int i = 0; i < 9; i++) {
        cin >> temp;
        v.at(i) = temp;
        m[temp] = i;
    }

    m[101] = 10;


    int sum;
    temp = 362880;
    while (temp > 0) {
        next_permutation(v.begin(), v.end());
        sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += v.at(i);
        }

        if (sum == 100) {
            break;
        }
        temp--;
    }

    set<int> s;
    for (int i = 0 ; i < 7; i++) {
        s.insert(v.at(i));
    }

    int min;
    while (!s.empty()) {
        min = 101;
        for (auto it : s) {
            if (m[it] < m[min]) {
                min = it;
            }
        }
        cout << min << endl;
        s.erase(min);
    }

    return 0;
}
