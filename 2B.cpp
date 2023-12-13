/*Write a menu driven program to perform following
operations on singly linked list: Create, reverse,
search, count and Display.
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int count;

public:
    LinkedList() {
        head = NULL;
        count = 0;
    }

    void create() {
        int data;
        cout << "Enter the data for the node: ";
        cin >> data;

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        count++;
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    int search(int key) {
        Node* current = head;
        int index = 0;
        while (current != NULL) {
            if (current->data == key) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    int countNodes() {
        return count;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int choice;
    LinkedList list;

    while (true) {
        cout << "1. Create Node" << endl;
        cout << "2. Reverse List" << endl;
        cout << "3. Search Element" << endl;
        cout << "4. Count Nodes" << endl;
        cout << "5. Display List" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.create();
                break;
            case 2:
                list.reverse();
                break;
            case 3: {
                int key;
                cout << "Enter the element to be searched: ";
                cin >> key;
                int index = list.search(key);
                if (index == -1) {
                    cout << "Element not found." << endl;
                } else {
                    cout << "Element found at index: " << index << endl;
                }
                break;
            }
            case 4:
                cout << "Number of nodes: " << list.countNodes() << endl;
                break;
            case 5:
                list.display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    }
    return 0;
}

