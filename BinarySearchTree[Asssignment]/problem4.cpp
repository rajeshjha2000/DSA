// Brothers From Different Roots [GFG]

/* Structure of the Node of the BST is as
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int countPairs(Node* root1, Node* root2, int x) {
        int ans = 0;  // Pairs count ko 0 se initialize karte hain
        stack<Node*> s1, s2;  // Do stacks use karte hain inorder aur reverse inorder traversal ke liye
        Node* a = root1;  // Tree 1 ke root node ko a se initialize karte hain
        Node* b = root2;  // Tree 2 ke root node ko b se initialize karte hain
        
        while (1) {
            // Inorder traversal for tree 1
            while (a) {
                s1.push(a);  // Current node ko stack mein push karte hain
                a = a->left;  // Left subtree mein move karte hain
            }
            // Reverse inorder traversal for tree 2
            while (b) {
                s2.push(b);  // Current node ko stack mein push karte hain
                b = b->right;  // Right subtree mein move karte hain
            }
            // Agar dono stacks khali hain to loop ko break karte hain
            if (s1.empty() || s2.empty()) {
                break;
            }

            auto atop = s1.top();  // Tree 1 ka top element lete hain
            auto btop = s2.top();  // Tree 2 ka top element lete hain
            
            int sum = atop->data + btop->data;  // Dono elements ka sum calculate karte hain
            
            if (sum == x) {  // Agar sum x ke barabar hai
                ++ans;  // Pairs count ko increment karte hain
                s1.pop();  // Stack 1 se top element ko pop karte hain
                s2.pop();  // Stack 2 se top element ko pop karte hain
                a = atop->right;  // Tree 1 ke right subtree mein move karte hain
                b = btop->left;  // Tree 2 ke left subtree mein move karte hain
            } else if (sum < x) {  // Agar sum x se chhota hai
                s1.pop();  // Stack 1 se top element ko pop karte hain
                a = atop->right;  // Tree 1 ke right subtree mein move karte hain
            } else {  // Agar sum x se bada hai
                s2.pop();  // Stack 2 se top element ko pop karte hain
                b = btop->left;  // Tree 2 ke left subtree mein move karte hain
            }
        }
        return ans;  // Total pairs count return karte hain
    }
};

/*
Time Complexity: O(N1 + N2), jahan N1 aur N2 respectively root1 aur root2 ke nodes ka count hai.
                 Har tree ke nodes ko ek baar visit karte hain.
Space Complexity: O(H1 + H2), jahan H1 aur H2 respectively root1 aur root2 ke heights hain.
                  Stacks mein maximum height tak elements store hote hain.
*/
