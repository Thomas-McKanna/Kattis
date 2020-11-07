#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int main() {
    int n, hash, collisions, unique, hash_table[255];
    set<string> strings;
    string file;

    cin >> n;
    while (n) {
        cin.ignore();
        collisions = 0;
        unique = n;
        memset(hash_table, 0, sizeof(hash_table));

        for (int i = 0; i < n; i++) {
            getline(cin, file);

            hash = file[0];
            for (int j = 1; j < file.length(); j++) {
                hash ^= file[j];
            }

            if (strings.find(file) != strings.end()) {
                unique--;
            } else {
                hash_table[hash]++;
            }
            strings.insert(file);
        }
        
        for (int i = 0; i < 255; i++) if (hash_table[i] > 1) {
            int p = hash_table[i];
            collisions += (p * (p - 1)) / 2;
        }

        cout << unique << " " << collisions << endl;

        cin >> n;
    }

    return 0;
}