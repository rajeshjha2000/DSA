// Diameter Of Binary Tree [LeetCode-543]

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
    int D = 0; // To store the maximum diameter

    // Function to calculate the height of the tree and update the diameter
    int height(TreeNode* root) {
        if (!root) return 0; // Base case: if the node is null, return height as 0

        // Recursively calculate the height of left and right subtrees
        int LH = height(root->left);
        int RH = height(root->right);

        // Calculate the diameter passing through the current node
        int currD = LH + RH;

        // Update the maximum diameter found so far
        D = max(D, currD);

        // Return the height of the tree
        return max(LH, RH) + 1;
    }

    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // Call the height function to update the diameter
        return D; // Return the maximum diameter found
    }
};
