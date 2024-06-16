#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    // Helper function to find the maximum subarray sum in the given range [start, end]
    int maxSumArrayHelper(vector<int>& v, int start, int end) {
        // Base case: if the range contains only one element, return that element
        if (start == end) {
            return v[start];
        }

        int maxLeftBorderSum = INT_MIN;  // Maximum sum that crosses the midpoint from the left
        int maxRightBorderSum = INT_MIN; // Maximum sum that crosses the midpoint from the right
        int mid = start + (end - start) / 2; // Find the midpoint to divide the array

        // Recursively find the maximum subarray sum in the left half
        int maxLeftSum = maxSumArrayHelper(v, start, mid);
        // Recursively find the maximum subarray sum in the right half
        int maxRightSum = maxSumArrayHelper(v, mid + 1, end);

        // Calculate the maximum left border sum
        int leftBorderSum = 0;
        for (int i = mid; i >= start; i--) {
            leftBorderSum += v[i];
            if (leftBorderSum > maxLeftBorderSum) {
                maxLeftBorderSum = leftBorderSum;
            }
        }

        // Calculate the maximum right border sum
        int rightBorderSum = 0;
        for (int i = mid + 1; i <= end; i++) {
            rightBorderSum += v[i];
            if (rightBorderSum > maxRightBorderSum) { // Correct comparison with maxRightBorderSum
                maxRightBorderSum = rightBorderSum;
            }
        }

        // The maximum sum that crosses the midpoint
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

        // Return the maximum of the left sum, right sum, and cross-border sum
        return max(maxLeftSum, max(maxRightSum, crossBorderSum));
    }

    // Main function to find the maximum subarray sum
    int maxSubArray(vector<int>& nums) {
        // Call the helper function on the entire array
        return maxSumArrayHelper(nums, 0, nums.size() - 1);
    }
};
