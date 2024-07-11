// Transform To Sum Tree [GFG]

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Ek di gayi tree ko aisi tree me convert karo jaha har node me uske left aur right subtrees
    // ke nodes ka sum ho original tree me

    int sum(Node* root){
        if(root == NULL){
            return 0; // Agar node null hai, toh 0 return karo
        }
        if(root->left == NULL && root->right == NULL){
            // Leaf node ke liye, node ka data temporary variable me store karo
            int temp = root->data;
            root->data = 0; // Leaf node ka data 0 kar do
            return temp; // Aur uska original data return karo
        }
        int lsum = sum(root->left); // Left subtree ka sum calculate karo
        int rsum = sum(root->right); // Right subtree ka sum calculate karo
        int temp = root->data; // Current node ka data temporary variable me store karo
        root->data = lsum + rsum; // Current node ka data left aur right subtree ke sum ke barabar kar do
        return root->data + temp; // Current node ka new data aur uska original data return karo
    }

    void toSumTree(Node *node)
    {
        sum(node); // Given tree ko sum tree me convert karne ke liye helper function call karo
    }
};
