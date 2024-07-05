// Path Sum II (Leetcode-113)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Helper function jo recursive call karke path sums ko store karega
    void solve(TreeNode* root, int targetSum, int sum, vector<int> temp, vector<vector<int>>& ans) {
        // Base case: agar node NULL hai to return karo
        if (root == NULL) {
            return;
        }

        // Current node ke value ko sum mein add karo aur temp path mein daalo
        sum += root->val;
        temp.push_back(root->val);

        // Check karo agar current node ek leaf node hai
        if (root->left == NULL && root->right == NULL) {
            // Agar sum targetSum ke barabar hai, to current path ko ans mein add karo
            if (targetSum == sum) {
                ans.push_back(temp);
            }
            return;
        }

        // Recursively left aur right subtrees ke path sums ko check karo
        solve(root->left, targetSum, sum, temp, ans);
        solve(root->right, targetSum, sum, temp, ans);
    }

    // Main function jo call karega helper function ko
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;  // Result store karne ke liye
        vector<int> temp;  // Current path store karne ke liye
        int sum = 0;  // Initial sum ko zero set karo
        solve(root, targetSum, sum, temp, ans);  // Helper function ko call karo
        return ans;  // Result return karo
    }
};
