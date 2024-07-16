// Check BST Has Dead End[GFG]

/* The Node structure is
struct Node {
    int data;
    Node* right;
    Node* left;
}; */

/* You are required to complete below method */
class Solution {
public:
    // Helper function to traverse the BST and check for dead ends
    void fun(Node* root, unordered_map<int, bool>& visited, bool& ans) {
        // Base case: Agar node null hai, to return kar do
        if (root == 0) return;

        // Current node ko visit karte hain aur mark karte hain visited
        visited[root->data] = 1;

        // Agar node leaf node hai
        if (root->left == 0 && root->right == 0) {
            int xp1 = root->data + 1; // Node value + 1
            int xm1 = root->data - 1 == 0 ? root->data : root->data - 1; // Node value - 1 (special case for 1)

            // Check karte hain agar (node value + 1) aur (node value - 1) dono visited hain
            if (visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()) {
                ans = true; // Agar dono visited hain, to dead end hai
                return;
            }
        }

        // Left aur right subtree ko recursively check karte hain
        fun(root->left, visited, ans);
        fun(root->right, visited, ans);
    }

    // Function to check if there is any dead end in the BST
    bool isDeadEnd(Node* root) {
        bool ans = false; // Result store karne ke liye variable (whether there's a dead end or not)
        unordered_map<int, bool> visited; // Map to track visited nodes
        fun(root, visited, ans); // Helper function ko call karte hain
        return ans; // Result return karte hain
    }
};

/*
Time Complexity: O(N), jahan N BST ke nodes ka count hai.
                 Har node ko ek baar visit karte hain traversal ke dauran.
Space Complexity: O(N), jahan N BST ke nodes ka count hai.
                  Space unordered_map ko store karne ke liye aur recursion stack ke liye use hota hai.
*/


