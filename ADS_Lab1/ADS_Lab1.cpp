// ADS_Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string course;
    int age;
};

//Input one student
void inputStudent(Student& s) {
    cout << "ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Name: ";
    getline(cin, s.name);

    cout << "Course: ";
    getline(cin, s.course);

    cout << "Age: ";
    cin >> s.age;
    cin.ignore();
}

//Display one student
void displayStudent(Student s) {
    cout << "ID: " << s.id << endl;
    cout << "Name: " << s.name << endl;
    cout << "Course: " << s.course << endl;
    cout << "Age: " << s.age << endl;
}

//Search student index
int findStudent(Student students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == id)
            return i;
    }
    return -1;
}

int main() {

    Student students[5];

    //Input
    cout << "Input Students\n\n";

    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << endl;
        inputStudent(students[i]);
        cout << endl;
    }

    // Display
    cout << "\nAll Students\n\n";

    for (int i = 0; i < 5; i++) {
        displayStudent(students[i]);
        cout << endl;
    }

    // Search
    int searchID;

    cout << "Enter ID to search: ";
    cin >> searchID;

    int index = findStudent(students, 5, searchID);

    if (index != -1)
        cout << "Found: " << students[index].name << endl;
    else
        cout << "Student not found.\n";

    // Update
    while (true) {

        string input;

        cout << "\nEnter ID to update (Q to quit): ";
        cin >> input;

        if (input == "Q" || input == "q")
            break;

        int id = stoi(input);

        index = findStudent(students, 5, id);

        if (index == -1) {
            cout << "Student not found.\n";
            continue;
        }

        string field;

        cout << "Change (id/name/course/age): ";
        cin >> field;
        cin.ignore();

        if (field == "id") {
            cin >> students[index].id;
        }
        else if (field == "name") {
            getline(cin, students[index].name);
        }
        else if (field == "course") {
            getline(cin, students[index].course);
        }
        else if (field == "age") {
            cin >> students[index].age;
        }
        else {
            cout << "Invalid field.\n";
            continue;
        }

        cout << "\nUpdated Student:\n";
        displayStudent(students[index]);
    }

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
