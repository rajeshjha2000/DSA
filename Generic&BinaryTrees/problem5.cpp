// Path Sum (Leetcode-112)

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
    // Helper function jo recursive call karke path sum check karega
    bool solve(TreeNode* root, int targetSum, int sum) {
        // Base case: agar node NULL hai to wapas false return karo
        if (root == NULL) {
            return false;
        }

        // Current node ke value ko sum mein add karo
        sum += root->val;
        // Check karo agar current node ek leaf node hai
        if (root->left == NULL && root->right == NULL) {
            // Agar sum targetSum ke barabar hai, to true return karo
            if (targetSum == sum) {
                return true;
            }
            // Agar sum targetSum ke barabar nahi hai, to false return karo
            else {
                return false;
            }
        }

        // Recursively left aur right subtrees ke path sum ko check karo
        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right, targetSum, sum);
        // Agar koi bhi subtree ka path sum targetSum ke barabar hai to true return karo
        return leftAns || rightAns;
    }

    // Main function jo call karega helper function ko
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;  // Initial sum ko zero set karo
        bool ans = solve(root, targetSum, sum);  // Helper function ko call karo
        return ans;  // Result return karo
    }
};
