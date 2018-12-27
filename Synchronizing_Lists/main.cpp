#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct Comp {
    bool operator()(const pair<int, int>& f, const pair<int, int>& s) {
        if (f.first < s.first) {
            return true;
        } else {
            return false;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    set<pair<int, int>, Comp> list_one;
    vector<int> list_two, ans;

    int temp, iter;
    while (n != 0) {
        iter = 0;
        list_one.clear();
        for (int i = 0; i < n; i++) {
            cin >> temp;
            list_one.insert(pair<int, int>(temp, iter));
            iter++;
        }
        list_two.clear();
        for (int i = 0; i < n; i++) {
            cin >> temp;
            list_two.push_back(temp);
        }
        sort(list_two.begin(), list_two.end());

        ans.clear();
        ans.resize(n);
        iter = 0;
        for (auto &it : list_one) {
            ans.at(it.second) = list_two.at(iter);
            iter++;
        }

        for (auto &it : ans) {
            cout << it << endl;
        }
        cout << endl;
        cin >> n;
    }

    return 0;
}
