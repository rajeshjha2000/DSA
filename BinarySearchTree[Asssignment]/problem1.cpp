// Inorder Successor in BST[GFG]

/* The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* inOrderSuccessor(Node* root, Node* x)
    {
        Node* succ = NULL;  // Successor ko NULL se initialize karte hain
        Node* curr = root;  // Current node ko root se initialize karte hain
        
        while(curr) {  // Jab tak current node NULL nahi hota
            if(curr->data > x->data) {  // Agar current node ka data x ke data se bada hai
                succ = curr;  // Successor ko current node se update karte hain
                curr = curr->left;  // Left subtree mein search karte hain
            }
            else {  // Agar current node ka data x ke data se chhota ya barabar hai
                curr = curr->right;  // Right subtree mein search karte hain
            }
        }
        
        return succ;  // Successor node return karte hain
    }
};
