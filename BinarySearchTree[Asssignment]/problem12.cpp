// Merge Two BSTs [GFG]

#include <vector>
#include <stack>
using namespace std;

// Node structure
// class Node {
//     int data;
//     Node *left;
//     Node *right;

//     // Node constructor
//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

class Solution {
  public:
    // Dono BSTs ke node values ko sorted order me return karne ke liye function
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans; // dono trees ke sorted elements store karega
        stack<Node*> sa, sb; // do stacks sa aur sb
        Node *a = root1, *b = root2; // do pointers a aur b

        while(a || b || !sa.empty() || !sb.empty()) {
            // saare nodes ko left subtree se stack me push karte hain
            while(a) {
                sa.push(a);
                a = a->left;
            }
            
            // saare nodes ko left subtree se stack me push karte hain
            while(b) {
                sb.push(b);
                b = b->left;
            }
            
            // dono stacks ka top compare karte hain aur chhote value ko result me daalte hain
            if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)) {
                auto atop = sa.top();
                ans.push_back(atop->data); // chhote value ko result me daalte hain
                sa.pop();
                a = atop->right; // right subtree ko process karne ke liye move karte hain
            } 
            else {
                auto btop = sb.top();
                sb.pop();
                ans.push_back(btop->data); // chhote value ko result me daalte hain
                b = btop->right; // right subtree ko process karne ke liye move karte hain
            }
        }
        
        return ans; // sorted result return karte hain
    }
};
