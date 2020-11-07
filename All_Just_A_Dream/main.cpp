#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<string> estack;
    unordered_map<string, int> emap;

    char c;
    int current = 0, itr;
    string event;
    for (int i = 0; i < n; i++) {
        cin >> c;

        if (c == 'E') {
            cin >> event;
            estack.push(event);
            emap[event] = current++;
        }

        if (c == 'D') {
            cin >> itr;
            for (int j = 0; j < itr; j++) {
                emap.erase(estack.top());
                estack.pop();
            }
            current -= itr;
        }

        if (c == 'S') {
            cin >> itr;
            int back_count = 0;
            bool plot_error = false;
            vector<string> events;
            for (int j = 0; j < itr; j++) {
                cin >> event;
                events.push_back(event);
            }
            sort(events.begin(), events.end());
            for (int j = 0; j < itr; j++) {
                event = events[j];
                if (event[0] == '!') {
                    if (emap.find(event.substr(1)) != emap.end()) {
                        back_count = max(back_count, 
                                         current-emap[event.substr(1)]);
                    }
                } else {
                    if (emap.find(event) == emap.end()) {
                        plot_error = true;
                    } else if (current - emap[event] <= back_count) {
                        // here we check for scenario where an event we 
                        // must 'undo' happened before this event
                        plot_error = true;
                    }
                }
            }
            
            if (plot_error) cout << "Plot Error" << endl;
            else if (back_count) {
                cout << back_count << " Just A Dream" << endl;
            } else cout << "Yes" << endl;
        }
    }
    
    return 0;
}
