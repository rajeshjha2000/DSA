// Lowest Common Ancestor Of Binary Search Tree [LeetCode-235]

/** Time Complexity: O(H)
Space Complexity: O(H)
Where H is height of BST */

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
        // Base case
        // Agar root NULL hai, toh NULL return karo
        if(root == NULL){
            return NULL;
        }

        // Case 1: P left subtree mein hai aur Q right subtree mein hai
        if(p->val < root->val && q->val > root->val){
            // Root common ancestor hai
            return root;
        }
        // Case 2: Q left subtree mein hai aur P right subtree mein hai
        else if(p->val > root->val && q->val < root->val){
            // Root common ancestor hai
            return root;
        }
        // Case 3: P aur Q left subtree mein hain
        else if(p->val < root->val && q->val < root->val){
            // Left subtree mein search karte hain
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }
        // Case 4: P aur Q right subtree mein hain
        else if(p->val > root->val && q->val > root->val){
            // Right subtree mein search karte hain
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }   

        // Agar koi specific case match nahi karta, toh root ko return karo
        return root; 
    }
};
