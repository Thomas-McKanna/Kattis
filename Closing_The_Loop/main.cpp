#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int> red, blue;

    int s, length, count;
    char color;
    string segment;
    for (int i = 0; i < n; i++) {
        cin >> s;
        red = priority_queue<int>();
        blue = priority_queue<int>();
        for (int j = 0; j < s; j++) {
            cin >> segment;
            color = segment.back();
            if (color == 'R') {
                red.push(stoi(segment.substr(0, segment.length() - 1)));
            } else if (color == 'B') {
                blue.push(stoi(segment.substr(0, segment.length() - 1)));
            }
        }

        length = 0;
        count = 0;
        while (!red.empty() && !blue.empty()) {
            length += red.top() + blue.top();
            count += 2;
            red.pop();
            blue.pop();
        }

        cout << "Case #" << i + 1 << ": " << length - count << endl;
    }

    return 0;
}
