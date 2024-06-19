#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to find combinations that sum up to the target
    void combinationSum_helper(vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>& ans, int index) {
        // Base case: if target is 0, we found a combination
        if(target == 0) {
            ans.push_back(v); // Add the current combination to the answer
            return;
        }

        // If target becomes negative, no valid combination can be formed
        if(target < 0) {
            return;
        }

        // Iterate through the candidates starting from the current index
        for(int i = index; i < candidates.size(); i++) {
            v.push_back(candidates[i]); // Include the current candidate in the combination

            // Recurse with the updated target and same index (candidates can be reused)
            combinationSum_helper(candidates, target - candidates[i], v, ans, i);

            // Backtrack: remove the last candidate added
            v.pop_back();
        }
    }

    // Main function to find all unique combinations of candidates that sum up to the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // To store all possible combinations
        vector<int> v; // To store a single combination
        combinationSum_helper(candidates, target, v, ans, 0); // Start the recursive process
        return ans; // Return all found combinations
    }
};
