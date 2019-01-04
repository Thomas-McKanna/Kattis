#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> p;
    int n;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        p.push_back(n);
    }

    bool no_swaps;
    for (size_t i = 0; i < p.size() - 1; i++) {
        no_swaps = true;
        for (size_t j = 0; j < p.size() - 1; j++) {
            if (p.at(j) > p.at(j + 1)) {
                no_swaps = false;
                n = p.at(j);
                p.at(j) = p.at(j + 1);
                p.at(j + 1) = n;
                for (auto it : p) {
                    cout << it << " ";
                }
                cout << endl;
            }
        }
        if (no_swaps) {
            break;
        }
    }

    return 0;
}
