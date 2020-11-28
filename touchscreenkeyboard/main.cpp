#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, string> is;

char keyboard[10][10] = {
    {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
    {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '$'},
    {'z', 'x', 'c', 'v', 'b', 'n', 'm', '$', '$', '$'}
};

int get_distance(char c1, char c2) {
    int h1, h2, v1, v2;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (keyboard[i][j] == c1) {
                v1 = i; h1 = j;
            }
            if (keyboard[i][j] == c2) {
                v2 = i; h2 = j;
            }
        }
    }
    return abs(v2 - v1) + abs(h2 - h1);
}

int main() {
    int t;
    cin >> t;

    string s, word;
    int l, total_distance;
    while (t--) {
        cin >> s >> l;
        vector<is> words;
        for (int i = 0; i < l; i++) {
            cin >> word;
            total_distance = 0;
            for (int j = 0; j < word.length(); j++) {
                total_distance += get_distance(word[j], s[j]);
            }
            words.push_back(is(total_distance, word));
        }
        sort(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++) {
            cout << words[i].second << " " << words[i].first << endl;
        }
    }

    return 0;
}
