/*. Write a menu driven program to perform following
operations on singly linked list: Create, Insert,
Delete, and Display.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Delete(int n) {
    Node* temp1 = head;
    if(n == 1) {
        head = temp1->next;
        delete temp1;
        return;
    }
    for(int i=0; i<n-2; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, x, n;
    while(1) {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter the element: ";
                    cin >> x;
                    insert(x);
                    break;
            case 2: cout << "Enter the element you want to delete: ";
                    cin >> n;
                    Delete(n);
                    break;
            case 3: display();
                    break;
            case 4: break;
            default: cout << "Invalid Input" << endl;
        }
    }
    return 0;
}

