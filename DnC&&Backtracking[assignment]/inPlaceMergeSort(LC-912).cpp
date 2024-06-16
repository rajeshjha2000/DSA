#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to merge two sorted subarrays in place
    void mergeInPlace(vector<int>& v, int start, int mid, int end) {
        int total_len = end - start + 1; // Total length of the array portion to be merged
        int gap = total_len / 2 + total_len % 2; // Initial gap value, ceil of total_len / 2

        while(gap > 0) { // Continue until gap is reduced to 0
            int i = start, j = start + gap; // Pointers for comparison
            
            while(j <= end) { // Ensure the second pointer stays within bounds
                if(v[i] > v[j]) { // If elements are out of order, swap them
                    swap(v[i], v[j]);
                }
                ++i, ++j; // Move both pointers forward
            }
            // Update gap for next pass, if gap is 1 or less, set to 0 to terminate the loop
            gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
        }
    }
    
    // Function to perform merge sort on the array
    void mergeSort(vector<int>& v, int start, int end) {
        // Base case: if the array portion has 1 or no elements, it's already sorted
        if(start >= end) {
            return;
        }
        
        int mid = start + (end - start) / 2; // Find the midpoint to divide the array
        // Recursively sort the first half
        mergeSort(v, start, mid);
        // Recursively sort the second half
        mergeSort(v, mid + 1, end);
        // Merge the two halves in place
        mergeInPlace(v, start, mid, end);
    }

    // Function to sort an array using merge sort
    vector<int> sortArray(vector<int>& nums) {
        // Call mergeSort on the entire array
        mergeSort(nums, 0, nums.size() - 1);
        return nums; // Return the sorted array
    }
};
