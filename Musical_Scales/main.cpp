#include <iostream>
#include <set>
#include <list>
#include <map>

using namespace std;

enum Note {A, As, B, C, Cs, D, Ds, E, F, Fs, G, Gs};
map<Note, string> note_to_str =
{
    {A, "A"},
    {As, "A#"},
    {B, "B"},
    {C, "C"},
    {Cs, "C#"},
    {D, "D"},
    {Ds, "D#"},
    {E, "E"},
    {F, "F"},
    {Fs, "F#"},
    {G, "G"},
    {Gs, "G#"},
};

map<string, Note> str_to_Note =
{
    {"A", A},
    {"A#", As},
    {"B", B},
    {"C", C},
    {"C#", Cs},
    {"D", D},
    {"D#", Ds},
    {"E", E},
    {"F", F},
    {"F#", Fs},
    {"G", G},
    {"G#", Gs}
};

Note semitone(Note n) {
    return (Note) (((int) n + 1) % 12);
}

Note tone(Note n) {
    return (Note) (((int) n + 2) % 12);
}

set<Note> make_scale(Note n) {
    set<Note> s;
    s.insert(n);
    n = tone(n);
    s.insert(n);
    n = tone(n);
    s.insert(n);
    n = semitone(n);
    s.insert(n);
    n = tone(n);
    s.insert(n);
    n = tone(n);
    s.insert(n);
    n = tone(n);
    s.insert(n);
    n = semitone(n);
    s.insert(n);

    return s;
}

int main()
{
    list<set<Note>> scales;

    for (int i = 0; i < 12; i++) {
        scales.push_back(make_scale((Note) i));
    }

    int n;
    cin >> n;

    set<Note> notes;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        notes.insert(str_to_Note[temp]);
    }

    Note iter = A;
    bool valid;
    bool at_least_one = false;
    for (auto i = scales.begin(); i != scales.end(); i++) {
        valid = true;
        for (auto j : notes) {
            if (i->find(j) == i->end()) {
                valid = false;
                break;
            }
        }
        if (valid) {
            at_least_one = true;
            cout << note_to_str[iter] << " ";
        }
        iter = semitone(iter);
    }

    if (!at_least_one) {
        cout << "none";
    }

    return 0;
}
