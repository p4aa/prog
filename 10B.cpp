/*Implement Binary Search.*/
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    int index = binarySearch(arr, n, key);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
    return 0;
}

