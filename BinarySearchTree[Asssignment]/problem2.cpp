/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/

Node* findPredecessor(Node* root, Node* p) {
    Node* pred = NULL;  // Predecessor ko NULL se initialize karte hain
    Node* curr = root;  // Current node ko root se initialize karte hain

    while(curr) {  // Jab tak current node NULL nahi hota
        if(curr->data < p->data) {  // Agar current node ka data p ke data se chhota hai
            pred = curr;  // Predecessor ko current node se update karte hain
            curr = curr->right;  // Right subtree mein search karte hain
        } else {  // Agar current node ka data p ke data se bada ya barabar hai
            curr = curr->left;  // Left subtree mein search karte hain
        }
    }
    
    return pred;  // Predecessor node return karte hain
}

/*
Time Complexity: O(H), jahan H BST ka height hai. 
                Sabse badi depth tak traversal karna pad sakta hai.
Space Complexity: O(1), constant extra space use karte hain.
                Hum sirf kuch pointers ka use kar rahe hain.
*/
