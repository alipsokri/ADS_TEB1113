#include <iostream>
using namespace std;

class Queue {
public:
    string arr[5];

    int front = 0;
    int rear = -1;

    void enqueue(string data) {
        if (rear == 4)
            return;

        arr[++rear] = data;
    }

    void dequeue() {
        if (front > rear)
            return;

        front++;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

		cout << endl;
    }
};

int main() {
    Queue* node = new Queue();

    node->enqueue("A");
    node->enqueue("B");
    node->enqueue("C");
    node->enqueue("D");

    cout << "Original Queue:" << endl;
    node->display();

    cout << "\nDequeue:" << endl;
    node->dequeue();

    node->display();

    return 0;
};

