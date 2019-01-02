#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int t = 0;
    size_t pos;
    string s;
    cin >> s;
    do {
        n++;
        pos = s.find("ae");
        if (pos != string::npos) {
            t++;
        }
        cin >> s;
    } while (!cin.eof());

    if ((double) t / n >= 0.4) {
        cout << "dae ae ju traeligt va";
    } else {
        cout << "haer talar vi rikssvenska";
    }

    return 0;
}
