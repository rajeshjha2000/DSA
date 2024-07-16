/*
Creation of heap using array:
Time Complexity: O(N), jahan N array me elements ka number hai.
Space Complexity: O(1), constant space ke liye.
*/

#include <iostream>
using namespace std;

// Heapify using recursion
void heapify(int *arr, int size, int index) {
    int leftIndex = 2 * index; // left child ka index
    int rightIndex = 2 * index + 1; // right child ka index
    int largestIndex = index;

    // Ab find karte hain -> largest index from three indices
    if (leftIndex <= size && arr[largestIndex] < arr[leftIndex]) {
        largestIndex = leftIndex;
    }
    if (rightIndex <= size && arr[largestIndex] < arr[rightIndex]) {
        largestIndex = rightIndex;
    }
    if (index != largestIndex) {
        // Ek case ko hum solve kar lenge
        swap(arr[largestIndex], arr[index]);

        // Ab recursion solve karega
        heapify(arr, size, largestIndex);
    }          
}

// Array ko heap me convert karna
void buildHeap(int *arr, int n) {
    // n/2 se shuru karte hain kyunki last non-leaf node ka index hota hai n/2
    for (int index = n / 2; index > 0; index--) {
        heapify(arr, n, index);
    }
}

int main() {
    int arr[] = {-1, 5, 10, 15, 20, 25, 12}; // -1 ka use 1-based indexing ke liye
    int n = 6; // array ka size
    buildHeap(arr, n);
  
    cout << "Printing Heap: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
Example 1:
Input: 
arr = [5, 10, 15, 20, 25, 12]

Output:
Printing Heap
25 20 15 5 10 12
*/
