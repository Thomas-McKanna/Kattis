#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double sum = 0;
    int num = 0;

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp >= 0) {
            sum += temp;
            num++;
        }
    }

    cout << sum / num;

    return 0;
}
