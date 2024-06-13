#include<iostream>
#include<vector>
using namespace std;

// Utility function to print subarrays starting from a specific index
void printSubArray_util(vector<int> &nums, int start, int end) {
    // Base case: if 'end' reaches the size of the array, return
    if (end == nums.size()) {
        return;
    }
    
    // Print current subarray from 'start' to 'end'
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // Recursive call to print the next subarray with the end index incremented by 1
    printSubArray_util(nums, start, end + 1);
}

// Function to print all subarrays of the given array
void printSubArray(vector<int> &nums) {
    // Loop over each starting index of the subarray
    for (int start = 0; start < nums.size(); start++) {
        int end = start; // Initialize 'end' to 'start'
        // Call the utility function to print subarrays starting from 'start'
        printSubArray_util(nums, start, end);
    }
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5}; // Initialize the array
    printSubArray(nums); // Print all subarrays
    return 0;
}
