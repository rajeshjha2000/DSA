// Sum Of Longest Bloodline Of A Tree[GFG]

/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    // Function jo height aur maximum sum ko pair ke form me return karta hai
    pair<int, int> height(Node* root) {
        if(!root) return {0, 0}; // Agar root null hai, to height aur sum dono 0 return karo
        
        // Left aur right subtree ke height aur sum ko recursively calculate karo
        auto lh = height(root->left);
        auto rh = height(root->right);
        
        int sum = root->data; // Current node ka data sum me include karo
        
        // Agar left aur right subtree ka height same hai
        if(lh.first == rh.first) {
            sum += lh.second > rh.second ? lh.second : rh.second; // Jo zyada sum wala hai, usko add karo
        }
        // Agar left subtree ka height zyada hai
        else if(lh.first > rh.first) {
            sum += lh.second; // Left subtree ka sum add karo
        }
        // Agar right subtree ka height zyada hai
        else {
            sum += rh.second; // Right subtree ka sum add karo
        }
        
        // Maximum height aur corresponding sum ko pair ke form me return karo
        return {max(lh.first, rh.first) + 1, sum};
    }
    
    // Function jo longest root to leaf path ka sum return karta hai
    int sumOfLongRootToLeafPath(Node *root) {
        auto h = height(root); // Height function call karo
        return h.second; // Longest path ka sum return karo
    }
};
