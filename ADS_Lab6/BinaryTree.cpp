#include <iostream>
using namespace std;

class Tree {
private:
    int value;
    Tree* left;
    Tree* right;

public:
    Tree(int v) : value(v), left(nullptr), right(nullptr) {}
    ~Tree() {
        delete left;
        delete right;
    }

    void insert(int v) {
        if (v < value) {
            if (left == nullptr)
                left = new Tree(v);
            else
                left->insert(v);

        }
        else if (v > value) {
            if (right == nullptr)
                right = new Tree(v);
            else
                right->insert(v);
        }
    }

    bool search(int v) const {
        if (v == value)
            return true;
        if (v < value)
            return left != nullptr && left->search(v);
        return right != nullptr && right->search(v);
    }

    void displayInOrder() const {
        if (left)
            left->displayInOrder();
        cout << value << " ";
        if (right)
            right->displayInOrder();
    }

    void displayPreOrder() const {
        cout << value << " ";
        if (left)
            left->displayPreOrder();
        if (right)
            right->displayPreOrder();
    }

    void displayPostOrder() const {
        if (left)
            left->displayPostOrder();
        if (right)
            right->displayPostOrder();
        cout << value << " ";
    }

    int height() const {

        int leftHeight = left ? left->height() : 0;
        int rightHeight = right ? right->height() : 0;
        return 1 + max(leftHeight, rightHeight);
    }
};
int main() {

    int order[] = { 4, 2, 6, 1, 3, 5, 7 };
    Tree* root = new Tree(order[0]);
    for (int i = 1; i < 7; i++) {
        root->insert(order[i]);
    }
    cout << "In-order: ";
    root->displayInOrder();
    cout << endl;

    cout << "Pre-order: ";
    root->displayPreOrder();
    cout << endl;

    cout << "Post-order: ";
    root->displayPostOrder();
    cout << endl;

    cout << "Height: ";
    cout << root->height() << endl;

    cout << "Search 5: ";
    cout << (root->search(5) ? "Found" : "Not Found") << endl;

    cout << "Search 9: ";
    cout << (root->search(9) ? "Found" : "Not Found") << endl;

    delete root;
    return 0;
}