// Kth Smallest Element In BST [LeetCode-230]

/**
 * Time Complexity: O(N)
Space Complexity: O(H)
Where N and H are number of nodes and Height of BST respectively
 */

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
    int kthSmallest(TreeNode* root, int &k) {
        // Base case 
        // Agar root NULL hai, toh -1 return karo
        if(root == NULL){
            return -1;
        }

        // Inorder traversal (Left, Node, Right)
        // Left subtree mein search karte hain
        int leftAns = kthSmallest(root->left, k);
        if(leftAns != -1){
            // Agar left subtree se answer mil gaya, toh wahi return karo
            return leftAns;
        }

        // Node
        k--;
        // Agar current node kth smallest element hai, toh uska value return karo
        if(k == 0){
            return root->val;
        }

        // Right subtree mein search karte hain
        int rightAns = kthSmallest(root->right, k);
        // Right subtree ka answer return karo
        return rightAns;
    }
};
