/*
Deletion Operation:
Time Complexity: O(log N), jahan N heap me elements ka number hai.
Space Complexity: O(1), jahan 1 constant hai.
*/

#include<iostream>
using namespace std;

class Heap
{
    public:
        int *arr; // array jo heap ko represent karega
        int capacity; // heap ki maximum capacity
        int size; // current number of elements in heap

        Heap(int capacity){
            this->arr = new int[capacity + 1]; // heap ko 1-based indexing ke liye
            this->capacity = capacity;

            // Size = current number of elements in heap
            this->size = 0;
        }

        // Heap Data Structure me Insertion Operation
        void insertion(int val){
            // Agar heap full hai to overflow message print karo
            if(size == capacity){
                cout<< "Heap Overflow" << endl;
                return;
            }

            // Size increase ho jayega (1-Based Indexing)
            size++;
            int index = size; // index naya element ka
            arr[index] = val; // naya element ko array me daalo

            // Value ko sahi position pe le jaane ke liye
            while (index > 1) {
                int parentIndex = index / 2; // parent node ka index
                if(arr[index] > arr[parentIndex]) {
                    // Swap kardo
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex; // index ko update karke parent node pe le jao
                } else {
                    // Loop ko stop kardo agar parent sahi jagah pe hai
                    break;
                }
            }
        }

        // Heap Data Structure me Deletion Operation
        int deleteFromHeap(){
            // Root element ko save karte hain jo delete hoga
            int savedRoot = arr[1];

            // Step 1: Replace root element with last element
            arr[1] = arr[size];
            // Last element ko delete kardo --> means size-1 ho jayega
            size--;

            // Step 2: Ab root element ko uski correct position par rakh do
            int index = 1;
            while (index <= size) {
                int leftIndex = 2 * index; // left child ka index
                int rightIndex = 2 * index + 1; // right child ka index
                int largestIndex = index;

                // Now find -> largest index from three indices
                // Check left index
                if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
                    largestIndex = leftIndex;
                }
                // Check right index
                if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
                    largestIndex = rightIndex;
                }
                // No changes in index -> loop break kardo
                if(index == largestIndex){
                    break;
                }
                else {
                    // Swap kardo aur index ko update karke largestIndex pe le jao
                    swap(arr[largestIndex], arr[index]);
                    index = largestIndex;
                }
            }

            // Deleted root element ko return kardo
            return savedRoot;
        }

        // Heap ko print karne ka function
        void printHeap(){
            for (int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    int capacity = 5; // heap ki capacity set karte hain
    Heap h(capacity);

    // Elements ko insert karte hain
    h.insertion(10);
    h.insertion(20);
    h.insertion(5);
    h.insertion(11);
    h.insertion(6);

    cout << "Printing Heap" << endl;
    h.printHeap();

    // Heap se element delete karte hain
    int ans = h.deleteFromHeap();
    cout << "Deleted Element: " << ans << endl;
    cout << "Printing Heap" << endl;
    h.printHeap();
}

/*
Example 1:
Input: 10 20 5 11 6

Output:
Before Deletion of Heap
20 11 5 10 6 
Deleted Element: 20
After Deletion of Heap
11 10 5 6 
*/
