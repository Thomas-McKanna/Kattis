#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> ans;

    int n;
    cin >> n;
    int t_old, t_new, speed, miles;
    while (n != -1) {
        miles = 0;
        t_old = 0;
        t_new = 0;
        for (int i = 0; i < n; i++) {
            cin >> speed >> t_new;
            miles += speed*(t_new - t_old);
            t_old = t_new;
        }
        ans.push_back(miles);
        cin >> n;
    }

    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " miles";
        if (next(it) != ans.end()) {
            cout << endl;
        }
    }

    return 0;
}
