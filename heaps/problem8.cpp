// Kth Smallest Element in an Array using Max Heap (GFG)
#include<iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k) {
    // Step 1: First create a Max Heap of size K
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        int element = arr[i];
        pq.push(element);
    }

    // Step 2: For the remaining elements in the array, if an element is smaller
    // than the root of the heap, replace the root with this element
    for (int i = k; i < n; i++) {
        int element = arr[i];
        if(pq.top() > element) {
            pq.pop();
            pq.push(element);
        }        
    }

    // The root of the heap is the Kth smallest element
    return pq.top();    
}

int main() {
    int arr[] = {3, 7, 4, 5, 8, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int ans = getKthSmallestElement(arr, n, k);
    cout << k << "th Smallest Element: " << ans << endl;
    return 0;
}

/*
Example 1:
INPUT:
arr[] = {3, 7, 4, 5, 8, 6, 9} and k=4

OUTPUT:
4th Smallest Element: 6

Example 2:
INPUT:
arr[] = {3, 7, 4, 5, 8, 6, 9} and k=3

OUTPUT:
3rd Smallest Element: 5
*/
