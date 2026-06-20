// ADS_Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next = NULL;
};

void insertion(Node*& head, string newName) {
    Node* newNode = new Node();
    newNode->name = newName;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deletion(Node*& head, string targetName) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->name == targetName) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << targetName << " deleted." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->name != targetName) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << targetName << " not found." << endl;
    }
    else {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << targetName << " deleted." << endl;
    }
}

void display_list(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* display_node = head;
    while (display_node != NULL) {
        cout << display_node->name << endl;
        display_node = display_node->next;
    }
}

int main() {
    Node* head = NULL;

    insertion(head, "Aiman");
    insertion(head, "Ahmad");
    insertion(head, "Anajana");
    insertion(head, "Jessy");

    cout << "--- Initial List ---" << endl;
    display_list(head);


    cout << "\n--- After deleting Ahmad ---" << endl;
    deletion(head, "Ahmad");
    display_list(head);

    cout << "\n--- After inserting Zara ---" << endl;
    insertion(head, "Zara");
    display_list(head);
    return 0;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
