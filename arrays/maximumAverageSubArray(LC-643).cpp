#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    double slidingWindow(vector<int>& nums, int k) {
        int i = 0, j = k - 1;
        int sum = 0;

        // Initial window sum
        for(int y = i; y <= j; y++) {
            sum += nums[y];
        }

        int maxSum = sum;

        // Slide the window
        while(j + 1 < nums.size()) {
            sum -= nums[i++];
            sum += nums[++j];
            maxSum = max(maxSum, sum);
        }

        // Calculate and return the maximum average
        double maxAvg = maxSum / (double) k;
        return maxAvg;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        return slidingWindow(nums, k);
    }
};
