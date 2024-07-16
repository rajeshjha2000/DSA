// Replace Every Element with the Least Greater Element on its Right[GFG]

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node with given value
    Node(int val) : data(val), left(0), right(0) {};
};

class Solution {
public:
    // Helper function to insert a value into the BST and find the inorder successor
    Node* insert(Node* root, int val, int &succ) {
        // Agar root null hai, to naya node banake return karte hain
        if (!root) return new Node(val);
        
        // Agar value root ke data se bada ya barabar hai
        if (val >= root->data) {
            root->right = insert(root->right, val, succ); // Right subtree mein insert karte hain
        }
        else {
            succ = root->data; // Agar value chhota hai, to current root successor banega
            root->left = insert(root->left, val, succ); // Left subtree mein insert karte hain
        }
        return root; // Return the root after insertion
    }

    // Function to find the least greater element on the right side for each element in the array
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(arr.size(), -1); // Initial answer array ko -1 se initialize karte hain
        Node* root = 0; // Initial BST ka root null hai
        for (int i = arr.size() - 1; i >= 0; i--) { // Array ko reverse order mein traverse karte hain
            int succ = -1; // Initial successor -1 set karte hain
            root = insert(root, arr[i], succ); // Current value ko BST mein insert karte hain
            ans[i] = succ; // Answer array mein successor store karte hain
        }
        return ans; // Final answer return karte hain
    }
};

/*
Time Complexity: O(N log N), jahan N array ka size hai.
                 Har element ko BST mein insert karte hain aur BST ka height average case mein log N hota hai.
Space Complexity: O(N), jahan N array ka size hai.
                  Space BST nodes ko store karne ke liye use hota hai.
*/
