// Range Sum Of BST[LeetCode-938]

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Agar root null hai, to sum 0 return kar do
        if(!root) return 0;
        
        int ans = 0; // Initial sum 0 se start karte hain

        bool wasInRange = false;
        
        // Agar root ka value given range ke beech mein hai
        if(root->val >= low && root->val <= high){
            wasInRange = true; // Ye indicate karta hai ke value range mein hai
            ans += root->val; // Root ka value sum mein add karte hain
        }

        // Agar value range mein tha
        if(wasInRange){
            ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high); // Left aur right subtree ko recursively call karte hain
        }
        else if(root->val < low){
            // Agar root ka value low se chhota hai, to right subtree ko call karte hain
            ans += rangeSumBST(root->right, low, high);
        }
        else if(root->val > high){
            // Agar root ka value high se bada hai, to left subtree ko call karte hain
            ans += rangeSumBST(root->left, low, high);
        }
        return ans; // Final sum return karte hain
    }
};

/*
Time Complexity: O(N), jahan N number of nodes hai BST mein.
                 Har node ko ek baar visit karte hain.
Space Complexity: O(H), jahan H height hai BST ki.
                  Recursion stack ke liye space use hota hai, worst case mein H == N ho sakta hai agar tree skewed hai.
*/
