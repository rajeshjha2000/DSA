// Same Tree [LeetCode- 100]

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
    // Function to check if two binary trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, they are identical
        if (!p && !q) {
            return true;
        }
        // If both trees are not empty, compare their values and their subtrees
        if (p && q) {
            return (p->val == q->val)  // Compare the values of the current nodes
                && isSameTree(p->left, q->left)  // Recursively check the left subtrees
                && isSameTree(p->right, q->right);  // Recursively check the right subtrees
        }
        // If one tree is empty and the other is not, they are not identical
        return false;
    }
};
