#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // a. Find the maximum value
    int findMax(Node* head) {
        int maxVal = head->data;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data > maxVal) {
                maxVal = temp->data;
            }
            temp = temp->next;
        }
        return maxVal;
    }

    // b. Count total nodes
    int countNodes(Node* head) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // c. Print even-numbered nodes
    void printEvenNodes(Node* head) {
        int pos = 1;
        Node* temp = head;
        while (temp != nullptr) {
            if (pos % 2 == 0) {
                cout << temp->data << " ";
            }
            temp = temp->next;
            pos++;
        }
        cout << endl;
    }

    // d. Split and swap the list halves
    void splitAndSwap(Node* &head) {
        if (!head || !head->next) return;  // Only 0 or 1 element

        // Count total nodes
        int count = countNodes(head);
        int mid = count / 2;
        Node* temp = head;

        // Traverse to the mid point
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        // Split the list into two halves
        Node* secondHalf = temp->next;
        temp->next = nullptr;

        // Swap the two halves
        Node* temp1 = secondHalf;
        while (temp1->next) {
            temp1 = temp1->next;
        }
        temp1->next = head;
        head = secondHalf;
    }

    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Original List: ";
    list.printList(list.head);

    // a. Find maximum value
    cout << "Maximum Value: " << list.findMax(list.head) << endl;

    // b. Count total nodes
    cout << "Total Nodes: " << list.countNodes(list.head) << endl;

    // c. Print even-numbered nodes
    cout << "Even Numbered Nodes: ";
    list.printEvenNodes(list.head);

    // d. Split and swap list halves
    list.splitAndSwap(list.head);
    cout << "After Splitting and Swapping: ";
    list.printList(list.head);

    return 0;
}