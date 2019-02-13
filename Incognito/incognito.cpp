#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    // Category mapped to the number of items in that category
    unordered_map<string, int> cat_and_num;

    int n;
    string name, cat;
    int ans; // Final answer stored in here
    for (int i = 0; i < t; i++) {
        cin >> n;
        cat_and_num.clear();
        for (int j = 0; j < n; j++) {
            cin >> name >> cat;
            // If the "key" already exists, increment the value it is mapped to
            if (cat_and_num.find(cat) != cat_and_num.end()) {
                cat_and_num[cat] += 1;
            // Else if te "key" doesn't yet exist, make it and store 1
            } else {
                cat_and_num[cat] = 1;
            }
        }
        ans = 1;
        // C++ 11 syntax
        for (auto p : cat_and_num) {
            ans *= p.second + 1; // Making a possibility tree
        }
        cout << ans - 1 << endl; // minus 1 because no items means no disguise
    }

    return 0;
}