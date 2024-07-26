// 1. House Robber (Leetcode-198)

// ================== Inclusive and Exclusive Pattern ========================= //

// ================== Approach 1: Normal Recursion Approach ================== //

class Solution {
public:
    int solveUsingRecursion(vector<int>&nums, int index){
        // Base case
        if(index >= nums.size()){  // Agar index array ke size se bada ya barabar ho gaya, to return 0
            return 0;
        }

        // Recursive Relation
        int include = nums[index] + solveUsingRecursion(nums, index+2);  // Current element include karke aage badhte hain
        int exclude = 0 + solveUsingRecursion(nums, index+1);  // Current element exclude karke aage badhte hain
        
        // Getting max amount from both
        int maxAmount = max(include, exclude);  // Dono cases me se max amount lete hain
        return maxAmount;
    }
    int rob(vector<int>& nums) {
        int index = 0;
        return solveUsingRecursion(nums, index);  // Recursion se solution nikalte hain
    }
};

// ================== Approach 2: Top Down Approach ================== //
class Solution {
public:
    int solveUsingMemo(vector<int>&nums, int index, vector<int> &dp){
        // Base case
        if(index >= nums.size()){  // Agar index array ke size se bada ya barabar ho gaya, to return 0
            return 0;
        }

        // Step 3: if max amount already exists then return ans
        if(dp[index] != -1){  // Agar answer pehle se dp array me hai to wahi return karte hain
            return dp[index];
        }

        // Step 2: store max amount and return ans using DP array
        // TOP DOWN: Traverse from 0 to N
        int include = nums[index] + solveUsingMemo(nums, index+2, dp);  // Current element include karke aage badhte hain
        int exclude = 0 + solveUsingMemo(nums, index+1, dp);  // Current element exclude karke aage badhte hain        
        dp[index] = max(include, exclude);  // Max amount ko dp array me store karte hain
        return dp[index];
    }
    int rob(vector<int>& nums) {
        // Step 1: create DP array
        int n = nums.size();
        vector<int> dp(n, -1);  // DP array ko -1 se initialize karte hain
        int index = 0;
        return solveUsingMemo(nums, index, dp);  // Memoization se solution nikalte hain
    }
};

// ================== Approach 3: Bottom-up ================== //
class Solution {
public:
    int solveUsingTabu(vector<int>&nums, int index){
        // Step 1: create DP array
        int n = nums.size();
        vector<int> dp(n, -1);  // DP array ko -1 se initialize karte hain

        // Step 2: fill initial data in DP array according to recursion base case
        dp[n-1] = nums[n-1];  // Last element ko dp array me directly store karte hain

        // Step 3: fill the remaining DP array according to recursion formula/logic
        // BOTTOM UP: Traverse from N to 0
        for(int index = n - 2; index >= 0; index--){
            int tempAns = 0;
            if(index + 2 < n){
                // Corner Case
                tempAns = dp[index+2];  // Index + 2 wale element ka amount lete hain
            }
            int include = nums[index] + tempAns;  // Current element include karte hain
            int exclude = 0 + dp[index+1];  // Current element exclude karte hain        
            dp[index] = max(include, exclude);  // Dono cases me se max amount lete hain
        }
        return dp[0];  // DP array ke first element me answer hoga
    }
    int rob(vector<int>& nums) {
        int index = 0;
        return solveUsingTabu(nums, index);  // Tabulation se solution nikalte hain
    }
};

// ================== Approach 4: Space Optimization Approach ================== //
class Solution {
public:
    int solveUsingSO(vector<int>&nums, int index){
        // Step 1: create DP array
        int n = nums.size();
        int next = 0;  // Next ka initial value 0 set karte hain
        int prev = nums[n-1];  // Prev me last element ka value set karte hain
        int curr = 0;  // Current ka initial value 0 set karte hain

        for(int index = n - 2; index >= 0; index--){
            int tempAns = 0;
            if(index + 2 < n){
                // Corner Case
                tempAns = next;  // Index + 2 wale element ka amount next me store hota hai
            }
            int include = nums[index] + tempAns;  // Current element include karte hain
            int exclude = 0 + prev;  // Current element exclude karte hain        
            curr = max(include, exclude);  // Dono cases me se max amount lete hain

            // Update krna bhool jata hu
            next = prev;  // Next ko prev se update karte hain
            prev = curr;  // Prev ko current se update karte hain
        }
        return prev;  // Prev me final answer hoga
    }
    int rob(vector<int>& nums) {
        int index = 0;
        return solveUsingSO(nums, index);  // Space Optimization se solution nikalte hain
    }
};
