// Problem 3: Balanced Binary Tree [LC-110]

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
    // Function binary tree ki height calculate karne ke liye
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0; // Khali tree ki height 0 hoti hai
        }

        int leftH = height(root->left);  // Left subtree ki height recursively calculate karen
        int rightH = height(root->right); // Right subtree ki height recursively calculate karen

        // Current node ki height uski subtrees ki height ke maximum + 1 hai
        int finalH = max(leftH, rightH) + 1;
        
        return finalH;
    }

    // Function yeh check karne ke liye ki binary tree height-balanced hai ya nahi
    bool isBalanced(TreeNode* root) {
        // Base case: Khali tree balanced hota hai
        if (root == NULL) {
            return true;
        }

        // Left aur right subtrees ki height calculate karen
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight); // Heights ka difference calculate karen

        // Check karen ki current node balanced hai ya nahi
        bool currentNode = (diff <= 1);

        // Recursively check karen ki left aur right subtrees balanced hain ya nahi
        bool leftSub = isBalanced(root->left);
        bool rightSub = isBalanced(root->right);

        // Tree balanced hai agar current node aur dono subtrees balanced hain
        return currentNode && leftSub && rightSub;
    }
};
