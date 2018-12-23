#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, y;
    cin >> n >> y;

    set<int> ob;
    int temp;
    for (int i = 0; i < y; i++) {
        cin >> temp;
        ob.insert(temp);
    }

    for (int i = 0; i < n; i++) {
        if (ob.find(i) == ob.end()) {
            cout << i << endl;
        }
    }

    cout << "Mario got " << ob.size() << " of the dangerous obstacles.";

    return 0;
}
