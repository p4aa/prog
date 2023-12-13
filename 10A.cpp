/*Implement Sequential Search.*/
#include <iostream>
using namespace std;

int sequentialSearch(int array[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i; // return the index of the key if found
        }
    }
    return -1; // return -1 if key is not found
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 3;
    int index = sequentialSearch(array, size, key);
    if (index != -1) {
        cout << "Key found at index " << index << endl;
    } else {
        cout << "Key not found" << endl;
    }
    return 0;
}

