#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string d) {
        data = d;
        next = NULL;
    }
};

class Queue {
public:
    Node* front = NULL;
    Node* rear = NULL;

    void enqueue(string data) {
        Node* newNode = new Node(data);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == NULL)
            return;

        Node* temp = front;

        front = front->next;

        delete temp;

        if (front == NULL)
            rear = NULL;
    }

    void display() {
        Node* curr = front;

        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
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

