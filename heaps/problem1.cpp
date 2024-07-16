/*
Insertion Operation:
Time Complexity: O(log N), jahan N heap me elements ka number hai.
Space Complexity: O(capacity), jahan capacity constant hai.
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

    // Element insert karte hain
    h.insertion(10);
    h.insertion(20);
    h.insertion(5);
    h.insertion(11);
    h.insertion(6);

    cout << "Printing Heap" << endl;
    h.printHeap();
}

/*
Example 1:
Input: 10 20
Output: 20 10

Example 2:
Input: 10 20 5 11 6
Output: 20 11 5 10 6
*/
