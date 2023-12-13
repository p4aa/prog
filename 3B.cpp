/*Write a menu driven program to perform operations
on doubly linked list.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// Insert a node at the front of the list
void push(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// Insert a node at the end of the list
void insert(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

// Delete a node at a specific position
void deleteNode(int position) {
    if (head == NULL)
        return;
    Node* temp = head;
    if (position == 0) {
        head = temp->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
    if (next != NULL)
        next->prev = temp;
}

// Print the list
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main menu
int main() {
    int choice, data, position;
    while (true) {
        cout << "1. Insert at front" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Print the list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                push(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                insert(data);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> position;
                deleteNode(position);
                break;
            case 4:
                printList();
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

