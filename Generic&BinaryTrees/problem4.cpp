// Lowest Common Ancestor of a Binary Tree (Leetcode-236)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: agar root NULL hai to wapas NULL return karo
        if(root == NULL){
            return NULL;
        }
        // Agar current node ka value p ke barabar hai, to p return karo
        if(root->val == p->val){
            return p;
        }
        // Agar current node ka value q ke barabar hai, to q return karo
        if(root->val == q->val){
            return q;
        }

        // Recursively left aur right subtree ka LCA khojo (Preorder traversal)
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        // LCA return karo
        // Agar dono leftAns aur rightAns NULL hain, to NULL return karo
        if(leftAns == NULL && rightAns == NULL) return NULL;
        // Agar leftAns non-NULL aur rightAns NULL hai, to leftAns return karo
        else if(leftAns != NULL && rightAns == NULL) return leftAns;
        // Agar leftAns NULL aur rightAns non-NULL hai, to rightAns return karo
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        // Agar dono leftAns aur rightAns non-NULL hain, to current node (root) return karo
        else return root;
    }
};
