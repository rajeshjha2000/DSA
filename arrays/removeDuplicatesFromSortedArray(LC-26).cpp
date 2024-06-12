#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Check if the array is empty. If it is, return 0 because there are no elements to process.
        if (nums.empty()) return 0;

        // Initialize two pointers:
        // 'i' is used to traverse the array starting from the second element.
        // 'j' points to the position of the last unique element found, starting from the first element.
        int i = 1;
        int j = 0;

        // Loop until 'i' has traversed the entire array.
        while (i < nums.size()) {
            // If the current element at 'i' is the same as the element at 'j',
            // it means 'nums[i]' is a duplicate, so just move the traversal pointer 'i' to the next element.
            if (nums[i] == nums[j]) {
                i++;
            } else {
                // If the current element at 'i' is different from the element at 'j',
                // it means 'nums[i]' is a new unique element.
                
                // Move the 'j' pointer to the next position to place the new unique element.
                j++;
                
                // Place the unique element at position 'j'.
                nums[j] = nums[i];
                
                // Move the traversal pointer 'i' to the next element.
                i++;
            }
        }

        // After the loop ends, 'j' points to the last unique element in the array.
        // The total number of unique elements is 'j + 1' (because 'j' is a zero-based index).
        return j + 1;
    }
};
