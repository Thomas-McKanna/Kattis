#include <iostream>
#include <cmath>
#include <unordered_set>
#include <list>

using namespace std;

class pokestop {
    public:
    int r, c;
    string name;

    pokestop() {
        r = 0;
        c = 0;
        name = "";
    }

    pokestop(int r, int c, string name) {
        this->r = r;
        this->c = c;
        this->name = name;
    }

    int dist_to(const pokestop& other) {
        return abs(r - other.r) + abs(c - other.c);
    }
};

int main() {

    int n;
    cin >> n;

    unordered_set<string> visited_pokemon;
    list<pokestop> unvisited_pokestops;

    int r, c;
    string p;
    int distance = 0;
    for (int i = 0; i < n; i++) {
        cin >> r >> c >> p;
        unvisited_pokestops.push_back(pokestop(r, c, p));
    }

    int min_dist; // holds value of closest distance from current stop
    list<pokestop>::iterator current, prev, min_stop, iter, temp;
    unvisited_pokestops.push_front(pokestop()); // put (0,0) at the front
    current = unvisited_pokestops.begin();
    while (unvisited_pokestops.size() > 1) {

        // Find closest pokestop
        min_dist = 201; // max possible distance between any two
        iter = unvisited_pokestops.begin();
        while (iter != unvisited_pokestops.end()) {
            if (current != iter && current->dist_to(*iter) < min_dist) {
                min_dist = current->dist_to(*iter);
                min_stop = iter;
            }
            iter++;
        }
        // Add it's name to visted list
        visited_pokemon.insert(min_stop->name);
        // Add the distance traveled
        distance += min_dist;
        prev = current;
        current = min_stop;
        unvisited_pokestops.erase(prev);

        // Delete in pokestops which have the pokemon we just got
        iter = unvisited_pokestops.begin();
        while (iter != unvisited_pokestops.end()) {
            if (current != iter && visited_pokemon.find(iter->name) != visited_pokemon.end()) {
                temp = iter;
                iter++;
                unvisited_pokestops.erase(temp);
            } else {
                iter++;
            }
        }


    }

    distance += current->dist_to(pokestop());

    cout << distance << endl;

    return 0;
}