// validate binary search tree [LeetCode-98]

// Time Complexity: O(N)
// Space Complexity: O(N)
// Where N is number of nodes

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
    // Helper function to validate the BST
    bool solve(TreeNode* root, long long int lowerBound, long long int upperBound){
        // Base case: if the current node is NULL, return true (valid BST)
        if(root == NULL){
            return true;
        }

        // Check if the current node's value is within the valid range
        bool cond1 = (root->val > lowerBound); // Value should be greater than lower bound
        bool cond2 = (root->val < upperBound); // Value should be less than upper bound

        // Recursively check the left subtree with updated upper bound
        bool LS = solve(root->left, lowerBound, root->val);
        // Recursively check the right subtree with updated lower bound
        bool RS = solve(root->right, root->val, upperBound);

        // Check if the current node and its subtrees are valid BSTs
        if(cond1 && cond2 && LS && RS){
            return true; // All conditions are met, it's a valid BST
        }
        else{
            return false; // One or more conditions are not met, it's not a valid BST
        }
    }

    // Function to validate if the given tree is a BST
    bool isValidBST(TreeNode* root) {
        // Define the initial bounds for the BST
        long long int lowerBound = -2147483657;
        long long int upperBound = 2147483657;

        // Call the helper function with the initial bounds
        bool ans = solve(root, lowerBound, upperBound);
        return ans; // Return the result
    }
};
