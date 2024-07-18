// Check if a given Complete Binary Tree is a Max Heap or not? (GFG)

/*
Time complexity: O(N), where N is the number of nodes in the binary tree
Space complexity: O(H), where H is the height of the binary tree.
*/
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Our Custom Pair Class
class OurPair {
public:
    int maxVal;
    bool isHeap;

    OurPair(int maxVal, bool isHeap) {
        this->maxVal = maxVal;
        this->isHeap = isHeap;
    }
};

// Node Class For CBT
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// CBT is a valid Max Heap or not (Using our pair)
OurPair checkMaxHeap(Node* root) {
    // Base Case 1: Root is Null
    if (root == NULL) {
        return OurPair(INT_MIN, true);
    }
    // Root null hai to isHeap true hai aur maxVal INT_MIN hai

    // Base Case 2: Root is a leaf node
    if (root->left == NULL && root->right == NULL) {
        return OurPair(root->data, true);
    }
    // Agar root leaf node hai to isHeap true hai aur maxVal root ka data hai

    OurPair leftAns = checkMaxHeap(root->left);
    OurPair rightAns = checkMaxHeap(root->right);
    // Left aur right subtree ka result nikal rahe hain

    // 1 case hum solve kr lenge
    if (root->data > leftAns.maxVal && 
        root->data > rightAns.maxVal && 
        leftAns.isHeap && rightAns.isHeap) {
        // Valid Max Heap
        return OurPair(max(root->data, max(leftAns.maxVal, rightAns.maxVal)), true);
    } else {
        // Not Valid Max Heap
        return OurPair(max(root->data, max(leftAns.maxVal, rightAns.maxVal)), false);
    }
    // Root ka data left aur right ke maxVal se bada hai aur dono subtree max heap hain
}

// CBT is a valid Max Heap or not (Using STL Pair)
pair<bool, int> checkMaxHeapSTL(Node* root) {
    // Base Case 1: Root is Null
    if (root == NULL) {
        return make_pair(true, INT_MIN);
    }
    // Root null hai to isHeap true hai aur maxVal INT_MIN hai

    // Base Case 2: Root is a leaf node
    if (root->left == NULL && root->right == NULL) {
        return make_pair(true, root->data);
    }
    // Agar root leaf node hai to isHeap true hai aur maxVal root ka data hai

    pair<bool, int> leftAns = checkMaxHeapSTL(root->left);
    pair<bool, int> rightAns = checkMaxHeapSTL(root->right);
    // Left aur right subtree ka result nikal rahe hain

    // 1 case hum solve kr lenge
    if (leftAns.first && 
        rightAns.first && 
        root->data > leftAns.second && 
        root->data > rightAns.second) {
        // Valid Max Heap
        return make_pair(true, root->data);
    } else {
        // Not Valid Max Heap
        return make_pair(false, root->data);
    }
    // Root ka data left aur right ke maxVal se bada hai aur dono subtree max heap hain
}

int main() {
    // Create a sample tree
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->left->right = new Node(20);
    root->right->left = new Node(35);
    // Sample tree banaya gaya hai

    OurPair result = checkMaxHeap(root);
    cout << "Is the tree a valid Max Heap? (Custom Pair): " << (result.isHeap ? "Yes" : "No") << endl;
    // Custom pair ke sath check kar rahe hain

    pair<bool, int> resultSTL = checkMaxHeapSTL(root);
    cout << "Is the tree a valid Max Heap? (STL Pair): " << (resultSTL.first ? "Yes" : "No") << endl;
    // STL pair ke sath check kar rahe hain

    return 0;
}
