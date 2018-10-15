#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

template <typename E>
struct AVLNode
{
    E element;
    AVLNode *left;
    AVLNode *right;
    int num_left;
    int num_right;
    int mult;
    int height;

    AVLNode(const E &ele, AVLNode *lt, AVLNode *rt, int h = 0)
        : element{ele}, left{lt}, right{rt}, height{h} {
            num_left = 0;
            num_right = 0;
            mult = 1;
        }
};

template <typename E>
class AVLTree {
private:

    AVLNode<E> *root;
    int size;

    int height(AVLNode<E> *t) const {
        if (t == nullptr) {
            return -1;
        } else {
            return t->height;
        }
    }

    AVLNode<E> * findMin(AVLNode<E> *t) const {
        if (t == nullptr) {
            return nullptr;
        }
        if (t->left == nullptr) {
            return t;
        }
        return findMin(t->left);
    }

    void insert(const E &x, AVLNode<E> *&t) {
        if (t == nullptr) {
            t = new AVLNode<E>(x, nullptr, nullptr);
            size++;
        } else if (x < t->element) {
            t->num_left++;
            //cout << "Inserting " << x << " to the left of " << t->element << endl;
            //cout << "Incrementing " << t->element << "s num_left to " << t->num_left << endl;
            insert(x, t->left);
        } else if (x > t->element) {
            t->num_right++;
            //cout << "Inserting " << x << " to the right of " << t->element << endl;
            //cout << "Incrementing " << t->element << "s num_right to " << t->num_right << endl;
            insert(x, t->right);
        } else {
            t->mult++;
            size++;
        }

        balance(t);
    }

    void increment_position(AVLNode<E> *t) {
        if (t == nullptr) {
            return;
        }
        t->kth_position++;
        increment_position(t->left);
        increment_position(t->right);
    }

    void decrement_position(AVLNode<E> *t) {
        if (t == nullptr) {
            return;
        }
        t->kth_position--;
        increment_position(t->left);
        increment_position(t->right);
    }

    void balance(AVLNode<E> *&t) {
        if (t == nullptr) {
            return;
        }

        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
            //cout << "UNBALANCE DETECTED: ";
            // CASE 1: LEFT-LEFT
            if (height(t->left->left) >= height(t->left->right)) {
                //cout << "Case 1 -> rotating with left child of " << t->element << endl;
                rotateWithLeftChild(t);
            // CASE 2: LEFT-RIGHT
            } else {
                //cout << "Case 2 -> double rotating with left child of " << t->element << endl;
                doubleWithLeftChild(t);
            }
        } else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE){
            //cout << "UNBALANCE DETECTED: ";
            // CASE 2: RIGHT-RIGHT
            if (height(t->right->right) >= height(t->right->left)) {
                //cout << "Case 4 -> rotating with right child of " << t->element << endl;
                rotateWithRightChild(t);
            // CASE 2: RIGHT-LEFT
            } else {
                //cout << "Case 3 -> double rotating with right child of " << t->element << endl;
                doubleWithRightChild(t);
            }
        }

        t->height = max(height(t->left), height(t->right)) + 1;
    }

    void rotateWithLeftChild(AVLNode<E> *&k2) {
        AVLNode<E> *k1 = k2->left;
        k2->num_left = k1->num_right;
        k1->num_right += k2->num_right + k2->mult; // +1 for the node k2
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2 = k1;
    }

    void rotateWithRightChild(AVLNode<E> *&k2) {
        AVLNode<E> *k1 = k2->right;
        k2->num_right = k1->num_left;
        k1->num_left += k2->num_left + k2->mult; // +1 for the node k2
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2 = k1;
    }

    void doubleWithLeftChild(AVLNode<E> *&k3) {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void doubleWithRightChild(AVLNode<E> *&k3) {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    void remove(const E &x, AVLNode<E> *&t) {
        if (t == nullptr) {
            return;
        }

        if (x < t->element) {
            t->num_left--;
            remove(x, t->left);
        } else if (x > t->element) {
            t->num_right--;
            remove(x, t->right);
        } else if (t->left != nullptr && t->right != nullptr) { // Two children
            t->element = findMin(t->right)->element;
            t->num_right--;
            remove(t->element, t->right);
        } else {
            AVLNode<E> *oldNode = t;
            if (t->left != nullptr) {
                t = t->left;
            } else {
                t = t->right;
            }
            delete oldNode;
            size--;
        }

        balance(t);
    }

    void remove(AVLNode<E> *&t, int key, int &offset, int &answer) {
        if (t == nullptr) {
            return;
        }

        if (key == 0 ) {
            return;
        }

        int position = offset + t->num_left + 1;

        if (t->mult > 1 && key >= position && key <= position + t->mult - 1) {
            answer = t->element;
            t->mult--;
            size--;
        } else if (key < position) {
            t->num_left--;
            remove(t->left, key, offset, answer);
        } else if (key > position) {
            t->num_right--;
            offset = position + t->mult - 1;
            remove(t->right, key, offset, answer);
        } else if (t->left != nullptr && t->right != nullptr) { // Two children
            answer = t->element;
            t->element = findMin(t->right)->element;
            t->mult = findMin(t->right)->mult;
            t->num_right--;
            remove(t->element, t->right);
        } else {
            answer = t->element;
            AVLNode<E> *oldNode = t;
            if (t->left != nullptr) {
                t = t->left;
            } else {
                t = t->right;
            }
            delete oldNode;
            size--;
        }

        balance(t);
    }

    void print(AVLNode<E> *t) {
        if (t == nullptr) {
            return;
        }

        print(t->left);
        cout << "| V: " << t->element <<  " L: " << t->num_left << " R: " << t->num_right << " | ";
        print(t->right);
    }

public:

    int getSize() {
        return size;
    }

    static const int ALLOWED_IMBALANCE = 1;

    AVLTree() {
        root = nullptr;
        size = 0;
    }

    void insert(E &x) {
        insert(x, root);
    }

    int remove() {
        int answer = -1;
        int offset = 0;
        if (size % 2 == 0) {
            remove(root, size / 2 + 1, offset, answer);
        } else {
            remove(root, (size + 1) / 2, offset, answer);
        }

        if (answer == 143194) {
            cout << "";
        }
        return answer;
    }

    void print() {
        print(root);
    }
};


int main()
{
    AVLTree<int> t;
    vector<int> temp;

    //ifstream Inputfile;
    //Inputfile.open("random_input");

    string d;
    int x;
    while (getline(cin, d).good()) {
        if (d == "#") {
            cout << t.remove() << endl;
        } else {
            x = stoi(d);
            t.insert(x);
        }
    }



    return 0;
}



/*
class MyTree {
private:
    class Node {
    public:
        unsigned int value;
        unsigned int multiplicity;
        unsigned int position;
        unsigned int height;
        Node *left_tree;
        Node *right_tree;

        Node(unsigned int d, unsigned int p, unsigned int h = 0) {
            value = d;
            multiplicity = 1;
            position = p;
            left_tree = nullptr;
            right_tree = nullptr;
            height = h;
        }
    };

    int height(Node *t) const {
        return t == nullptr ? -1 : t->height;
    }

    Node *root;

    unsigned int size;

    void rec_insert(Node *current, unsigned int x) {
        if (x > current->value) {
            if (current->right_tree == nullptr) {
                current->right_tree = new Node(x, current->position + 1, current->height + 1);
            } else {
                rec_insert(current->right_tree, x);
            }
        } else if (x < current->value) {
            current->position = current->position + 1;
            if (current->left_tree == nullptr) {
                current->left_tree = new Node(x, current->position - 1, current->height + 1);
            } else {
                rec_insert(current->left_tree, x);
            }
        } else {
            current->position = current->position + 1;
            current->multiplicity = current->multiplicity + 1;
        }

        balance()
    }

    int rec_remove(Node *n) {
        if (n == nullptr) {
            return -1;
        } else if (n->position == size / 2) {
            return n->value;
        }
    }

    void rec_print(Node *n) {
        if (n == nullptr) {
            return;
        }

        rec_print(n->left_tree);
        cout << "| " << "V: " << n->value << " P: " << n->position << " | ";
        rec_print(n->right_tree);
    }

public:

    MyTree() {
        root = nullptr;
        size = 0;
    }

    void insert(unsigned int x) {
        if (root == nullptr) {
            root = new Node(x, 1);
        } else {
            rec_insert(root, x);
        }
    }

    int remove() {
        return -1;
    }

    void print() {
        rec_print(root);
    }
};
*/
