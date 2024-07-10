// Balanced Binary Tree [LeetCode - 110]

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
    bool isBal = true; // Flag to indicate if the tree is balanced

    // Function to calculate the height of the tree and check for balance
    int height(TreeNode* root) {
        if (!root) return 0; // Base case: if the node is null, return height as 0

        // Recursively calculate the height of left and right subtrees
        int LH = height(root->left);
        int RH = height(root->right);

        // Check if the current node is balanced
        if (isBal && abs(LH - RH) > 1) {
            isBal = false; // Set the flag to false if the current node is not balanced
        }

        // Return the height of the tree
        return max(LH, RH) + 1;
    }

    // Function to check if the binary tree is balanced
    bool isBalanced(TreeNode* root) {
        height(root); // Call the height function to check balance and calculate height
        return isBal; // Return whether the tree is balanced
    }
};
