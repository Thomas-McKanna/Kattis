#include <iostream>

using namespace std;

struct Card {
    int val;
    Card* next;
    Card * prev;
};

class Deck {
private:
    Card *top;
    int num_cards;

public:
    Deck() {
        top = nullptr;
        num_cards = 0;
    }

    ~Deck() {
        Card* curr = top->next;
        for (int i = 0; i < num_cards; i++) {
            delete curr->prev;
            curr = curr->next;
        }
    }

    int get_top() {
        return top->val;
    }

    void place_top(int val) {
        if (top == nullptr) {
            top = new Card;
            top->val = val;
            top->prev = top;
            top->next = top;
        } else {
            Card* new_card = new Card;
            new_card->val = val;
            new_card->next = top;
            new_card->prev = top->prev;
            new_card->prev->next = new_card;
            top->prev = new_card;
            top = new_card;
        }
        num_cards++;
    }

    void top_to_bot() {
        top = top->next;
    }

    void bot_to_top() {
        top = top->prev;
    }

    void print_deck() {
        Card* curr = top;
        for (int i = 0; i < num_cards; i++) {
            cout << curr->val;
            if (i < num_cards - 1) {
                cout << " ";
            }
            curr = curr->next;
        }
    }

    void remove_all() {
        if (top == nullptr) {
            return;
        }

        Card* curr = top->next;
        for (int i = 0; i < num_cards; i++) {
            delete curr->prev;
            curr = curr->next;
        }
        top = nullptr;
        num_cards = 0;
    }
};

int main()
{
    int t;
    cin >> t;

    Deck d;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        d.remove_all();
        for (int j = n; j > 0; j--) {
            d.place_top(j);
            for (int k = 0; k < j; k++) {
                d.bot_to_top();
            }
        }
        d.print_deck();
        cout << endl;
    }

    return 0;
}
