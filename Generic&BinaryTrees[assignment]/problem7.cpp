// ZigZag Level order traversal [Leetcode-103]

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans; // Agar root null hai, toh empty vector return karo

        bool LtoR = true; // Level ka order, pehla level left to right hoga
        queue<TreeNode*> q; // BFS ke liye queue
        q.push(root);

        while(!q.empty()){
            int width = q.size(); // Current level ka size
            vector<int> oneLevel(width); // Current level ke nodes store karne ke liye vector

            for(int i = 0; i < width; i++){
                TreeNode* front = q.front(); // Queue se front node nikalna
                q.pop();
                
                // Index set karna based on current direction
                int index = LtoR ? i : width - i - 1;
                oneLevel[index] = front->val;

                // Left child ko queue me push karna agar exist karta hai
                if(front->left){
                    q.push(front->left);
                }
                // Right child ko queue me push karna agar exist karta hai
                if(front->right){
                    q.push(front->right);
                }
            }

            // Direction toggle karna next level ke liye
            LtoR = !LtoR;

            // Current level ko result me add karna
            ans.push_back(oneLevel);
        }

        return ans;
    }
};
