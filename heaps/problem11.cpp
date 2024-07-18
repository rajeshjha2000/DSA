// Check Whether a Binary Tree is a Complete Binary Tree or Not (Leetcode-958)

/*
Time Complexity: O(N)
Space Complexity: O(N)
Where N is number of nodes in binary tree
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;  // Queue create kar rahe hain

        q.push(root);  // Initially root ko queue me daal rahe hain
        bool nullFound = false;  // Null node milne ka flag set kar rahe hain

        while(!q.empty())  // Queue jab tak empty nahi hoti, loop chalate hain
        {
            TreeNode* front = q.front();  // Queue ke front element ko lete hain
            q.pop();  // Front element ko queue se nikalte hain

            if(front == NULL)  // Agar front null hai
            {
                nullFound = true;  // Null node mil gaya
            }
            else
            {
                if(nullFound == true)  // Agar pehle null node mil chuki hai
                {
                    return false;  // To tree complete binary tree nahi hai
                }
                q.push(front->left);  // Left child ko queue me daalte hain
                q.push(front->right);  // Right child ko queue me daalte hain
            }
        }

        return true;  // Agar null node ke baad koi non-null node nahi mili, to tree complete binary tree hai
    }
};
