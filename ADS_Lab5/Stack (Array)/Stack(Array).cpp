#include <iostream>
using namespace std;

class Stack {
public:
    string arr[5];
    int top = -1;

    void push(string data) {
        if (top == 4) return;

        arr[++top] = data;
    }

    void pop() {
        if (top == -1) return;

        top--;
    }

    void peek() {
        if (top != -1)
            cout << arr[top] << endl;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << endl;
    }
};

int main() {
    Stack* stack = new Stack();

    stack->push("A");
    stack->push("B");
    stack->push("C");
    stack->push("D");

    cout << "Original Stack:" << endl;
    stack->display();

    cout << "\nPeek:" << endl;
    stack->peek();

    cout << "\nPop once:" << endl;
    stack->pop();

    stack->display();

    return 0;
};

