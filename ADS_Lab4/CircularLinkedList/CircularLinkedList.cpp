#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = this;
        prev = this;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;

        newNode->next = head;
        head->prev = newNode;
    }

    void insertAfter(string afterName, string newName) {
        if (head == nullptr) return;

        Node* current = head;

        do {
            if (current->name == afterName) {
                Node* newNode = new Node(newName);

                newNode->next = current->next;
                newNode->prev = current;

                current->next->prev = newNode;
                current->next = newNode;

                return;
            }
            current = current->next;
        } while (current != head);

        cout << afterName << " not found.\n";
    }

    void deleteByName(string name) {
        if (head == nullptr) return;

        Node* current = head;

        do {
            if (current->name == name) {

                if (current->next == current) {
                    delete current;
                    head = nullptr;
                    return;
                }

                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head) {
                    head = current->next;
                }

                delete current;
                return;
            }

            current = current->next;
        } while (current != head);
    }

    void display() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        Node* current = head;

        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head);
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }

        Node* current = head->prev;

        do {
            cout << current->name << endl;
            current = current->prev;
        } while (current != head->prev);
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "\nInitial list:\n";
    list.display();

    cout << "\nAfter inserting Ali after Anjana:\n";
    list.insertAfter("Anjana", "Ali");
    list.display();

    cout << "\nAfter inserting Ahmad at the end:\n";
    list.insertEnd("Ahmad");
    list.display();

    cout << "\nAfter deleting Jessy:\n";
    list.deleteByName("Jessy");
    list.display();

    cout << "\nReverse linked list:\n";
    list.displayReverse();

    cout << "\nFinal list:\n";
    list.display();
}

