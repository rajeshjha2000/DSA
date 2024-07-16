// Build BST Using Preorder Traversal[LeetCode-1008]

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
    TreeNode* build(int &i, int min, int max, vector<int>& preorder) {
        // Base case: agar index i preorder size ke barabar ya usse bada hai
        if (i >= preorder.size()) {
            return NULL;
        }

        TreeNode* root = NULL;
        // Agar current element min aur max ke beech mein hai to yeh valid node ban sakta hai
        if (preorder[i] > min && preorder[i] < max) {
            root = new TreeNode(preorder[i++]);  // New node banate hain aur index i ko increment karte hain
            root->left = build(i, min, root->val, preorder);  // Left subtree build karte hain
            root->right = build(i, root->val, max, preorder);  // Right subtree build karte hain
        }

        return root;  // Root node return karte hain
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN, max = INT_MAX;  // Min aur Max ko initialize karte hain
        int i = 0;  // Index ko initialize karte hain
        return build(i, min, max, preorder);  // BST build karte hain
    }
};

/*
Time Complexity: O(N), jahan N preorder traversal ke elements ka size hai. 
                 Har element ko ek baar process karte hain.
Space Complexity: O(H), jahan H BST ka height hai. 
                  Recursion stack ke liye height tak space lagta hai.
*/

