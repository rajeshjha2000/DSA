/*
Heapification Operation:
Time Complexity: O(log N), jahan N array me elements ka number hai.
Space Complexity: O(log N), jahan log N binary tree ki maximum height hai.
*/

#include <iostream>
using namespace std;

void heapify(int *arr, int size, int index){
    int leftIndex = 2 * index; // left child ka index
    int rightIndex = 2 * index + 1; // right child ka index
    int largestIndex = index;

    // Ab find karte hain -> largest index from three indices
    if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
        largestIndex = leftIndex;
    }
    if (rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
        largestIndex = rightIndex;
    }
    if(index != largestIndex){
        // Ek case ko hum solve kar lenge
        swap(arr[largestIndex], arr[index]);

        // Ab recursion solve karega
        heapify(arr, size, largestIndex);
    }          
}

int main() {
    int arr[] = {-1, 12, 50, 60, 13}; // -1 ka use 1-based indexing ke liye
    int n = 4; // heap ka size
    heapify(arr, n, 1);
    
    cout << "Printing Heap: " << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
Example 1:
Input: 
arr = [12, 50, 60, 13]

Output:
Printing Heap
60 50 12 13

Example 2:
Input: 
arr = [5, 10, 15, 20, 25, 12]

Output:
Printing Heap
15 10 12 20 25 5
*/
