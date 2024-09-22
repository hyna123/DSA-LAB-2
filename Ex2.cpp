#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    Node* next;
};

class StudentList {
public:
    Node* head;

    StudentList() {
        head = nullptr;
    }

    void insertStudent(int id, string name) {
        Node* newNode = new Node();
        newNode->id = id;
        newNode->name = name;
        newNode->next = head;
        head = newNode;
    }

    void searchStudent(int id) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Student Found: " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!" << endl;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    StudentList list;
    list.insertStudent(1, "John");
    list.insertStudent(2, "Doe");
    list.insertStudent(3, "Alice");

    cout << "Student List: " << endl;
    list.printList();

    cout << "Search Student with ID 2:" << endl;
    list.searchStudent(2);

    return 0;
}