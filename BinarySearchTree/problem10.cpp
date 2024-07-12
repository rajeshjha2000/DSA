// Two Sum IV - Input In A BST [LeetCode-653]

/**
 * Time Complexity: O(N)
Space Complexity: O(N)
Where N is number of nodes of BST
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
    void storeInorder(TreeNode* root, vector<int> &inorder){
        // Base case
        // Agar root NULL hai, toh return kar do
        if(root == NULL){
            return;
        }

        // Inorder traversal (Left, Node, Right)
        // Left subtree ko traverse karo
        storeInorder(root->left, inorder);
        // Node value ko inorder array mein store karo
        inorder.push_back(root->val);
        // Right subtree ko traverse karo
        storeInorder(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        // Step 1: Inorder array banaye
        vector<int> inorder;
        storeInorder(root, inorder);

        // Step 2: Check karo ki target sum exist karta hai ya nahi
        int start = 0; // Starting index
        int end = inorder.size()-1; // Ending index

        while(start < end){
            int sum = inorder[start] + inorder[end];
            // Agar sum target ke barabar hai toh true return karo
            if(sum == k){
                return true;
            }
            // Agar sum target se chhota hai, toh start index badhao
            else if(sum < k){
                start++;
            }
            // Agar sum target se bada hai, toh end index ghatayo
            else if(sum > k){
                end--;
            }
        }

        // Agar sum nahi mila toh false return karo
        return false;
    }
};
