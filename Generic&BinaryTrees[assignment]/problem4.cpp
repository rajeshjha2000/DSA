// Symmetric Tree [LeetCode- 101]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x, left(left), right(right)) {}
 * };
 */
class Solution {
public:
    // Yeh function do trees ko mirror images hone ke liye check karta hai
    bool isMirror(TreeNode* p, TreeNode* q) {
        // Agar dono trees empty hain, toh woh mirror images hain
        if(!p && !q){
            return true;
        }
        // Agar dono trees empty nahi hain, toh unke values aur unke subtrees ko check karo
        if(p && q){
            return (p->val == q->val)  // Current nodes ke values ko compare karo
                && isMirror(p->left, q->right)  // Recursively left subtree ko right subtree ke saath check karo
                && isMirror(p->right, q->left);  // Recursively right subtree ko left subtree ke saath check karo
        }
        // Agar ek tree empty hai aur doosra nahi hai, toh woh mirror images nahi hain
        return false;
    }

    // Yeh function check karta hai ki tree symmetric hai ya nahi
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);  // Root ke left aur right subtree ko mirror image hone ke liye check karo
    }
};
