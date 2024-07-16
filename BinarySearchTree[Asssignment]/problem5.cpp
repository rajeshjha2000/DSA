// convert BST to a Balanced BST [LeetCode-1382]

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
    void inorder(TreeNode* root, vector<int>& in) {
        // Agar root NULL hai to return kar do
        if (!root) return;
        // Left subtree ke inorder traversal ko call karte hain
        inorder(root->left, in);
        // Current node ka value inorder list mein push karte hain
        in.push_back(root->val);
        // Right subtree ke inorder traversal ko call karte hain
        inorder(root->right, in);
    }

    TreeNode* buildTree(vector<int>& in, int start, int end) {
        // Base case: agar start index end se bada hai to NULL return karte hain
        if (start > end) return NULL;

        // Mid index ko calculate karte hain
        int mid = (start + end) / 2;
        // Mid value ko root banate hain
        TreeNode* root = new TreeNode(in[mid]);
        // Left subtree ko recursively build karte hain
        root->left = buildTree(in, start, mid - 1);
        // Right subtree ko recursively build karte hain
        root->right = buildTree(in, mid + 1, end);
        return root;  // Root node ko return karte hain
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);  // Inorder traversal karte hain aur sorted list ko generate karte hain

        // Inorder traversal se balanced BST build karte hain
        return buildTree(in, 0, in.size() - 1);
    }
};

/*
Time Complexity: O(N), jahan N BST ke nodes ka count hai. 
                 Inorder traversal aur balanced BST build karna, dono O(N) mein hote hain.
Space Complexity: O(N), vector in ko store karne ke liye O(N) space lagta hai.
                  Recursion stack depth O(log N) hoti hai (balanced BST mein).
*/
