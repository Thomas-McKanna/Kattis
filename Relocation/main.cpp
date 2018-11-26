#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    unordered_map<int, int> companies;

    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        companies[i] = temp;
    }

    char request_type;
    int first, second;
    for (int i = 0; i < q; i++) {
        cin >> request_type >> first >> second;
        if (request_type == '1') {
            companies[first] = second;
        } else if (request_type == '2') {
            cout << abs(companies[first] - companies[second]) << endl;
        }
    }

    return 0;
}
