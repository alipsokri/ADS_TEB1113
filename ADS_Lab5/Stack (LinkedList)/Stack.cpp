#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
    string name;
    Stack* next = NULL;
    Stack* curr_node = NULL;

    void push(string name) {
        Stack* newnode = new Stack();
        newnode->name = name;
        newnode->next = curr_node;
        curr_node = newnode;
    }

    void pop() {
        if (curr_node == NULL) return;

        Stack* temp = curr_node;
        curr_node = curr_node->next;

        delete temp;
    }

    void peek() {
        if (curr_node == NULL) return;

        cout << "top element= " << curr_node->name << endl;
    }
    void display_stack() {
        Stack* display_node = curr_node;
        while (display_node != NULL) {
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
    }
};

int main() {
    Stack* stack = new Stack();

    stack->push("A");
    stack->push("B");
    stack->push("C");
    stack->push("D");

    cout << "Original Stack:" << endl;
    stack->display_stack();

    cout << "\nPeek:" << endl;
    stack->peek();

    cout << "\nPop once:" << endl;
    stack->pop();

    stack->display_stack();

    return 0;
};
