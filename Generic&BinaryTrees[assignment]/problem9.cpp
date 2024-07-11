// Path Sum III [LeetCode-437]

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
    int ans = 0;

    // Ek root se shuru hone wale path ko check karna ke liye function
    void pathFromOneRoot(TreeNode* root, long long sum){
        if(!root) return; // Agar root null hai, to function se return kar jao

        // Agar current node ka value sum ke barabar hai to path mil gaya
        if(sum == root->val ){
            ++ans; // Path count badhao
        }

        // Left subtree me search karo baki sum ke saath
        pathFromOneRoot(root->left, sum - root->val);
        // Right subtree me search karo baki sum ke saath
        pathFromOneRoot(root->right, sum - root->val);
    }

    // Tree ke har node se shuru hone wale paths ko check karna ke liye function
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            // Har node se shuru hone wale paths ko check karo
            pathFromOneRoot(root, targetSum);
            // Left subtree ke nodes se paths check karo
            pathSum(root->left, targetSum);
            // Right subtree ke nodes se paths check karo
            pathSum(root->right, targetSum);
        }
        return ans; // Total paths ka count return karo
    }
};
