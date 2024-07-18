// C++ STL Priority Queue "MAX HEAP"
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create Max Heap (Max Priority Queue)
    priority_queue<int> maxPQ;

    // Insertion
    maxPQ.push(10);
    maxPQ.push(20);
    maxPQ.push(30);
    maxPQ.push(40);
    maxPQ.push(50);

    // Output the top element
    cout << "Top (Root) element of Max Heap: " << maxPQ.top() << endl;
    // Output the size of the heap
    cout << "Size of Max Heap: " << maxPQ.size() << endl;
    // Check if the heap is empty
    cout << "Max Heap is empty or not: " << (maxPQ.empty() ? "Yes" : "No") << endl;

    // Deletion
    maxPQ.pop();
    // Output the size of the heap after deletion
    cout << "Size of Max Heap: " << maxPQ.size() << endl;

    return 0;
}

/*
OUTPUT:
Top (Root) element of Max Heap: 50
Size of Max Heap: 5
Max Heap is empty or not: No
Size of Max Heap: 4
*/

/*
 Create Max Heap (Max Priority Queue)
........................................

Example: 
priority_queue<int> maxPQ;

Explanation: 
priority_queue<data_type> pq_name

1. Data Type: This is the data type of the elements that will be stored in the priority queue.
In this case, the priority queue will store integers.

Operations of priority queue:
Method    | Time Complexity | Space Complexity
----------|-----------------|-----------------
empty()   |       O(1)      |       O(1)
size()    |       O(1)      |       O(1)
top()     |       O(1)      |       O(1)
push()    |     O(log N)    |       O(1)
pop()     |     O(log N)    |       O(1)

*/