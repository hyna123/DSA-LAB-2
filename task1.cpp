#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Setting up the linked list
    Node* first = new Node{5, nullptr};
    first->next = new Node{10, nullptr};
    first->next->next = new Node{15, nullptr};

    Node* ptr = first;

    // Outputs
    cout << first->data << endl;               // Output: 5
    cout << first->next->next->data << endl;   // Output: 15
    cout << ptr->next->data << endl;           // Output: 10

    return 0;
}