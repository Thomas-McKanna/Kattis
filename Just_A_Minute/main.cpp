#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, s;

    cin >> n;

    int m_sum = 0;
    int s_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> m >> s;
        m_sum += m;
        s_sum += s;
    }

    double ans = (double) s_sum / (m_sum * 60);

    if (ans <= 1.0) {
        cout << "measurement error";
    } else {
        cout << fixed << setprecision(9);
        cout << ans;
    }

    return 0;
}
