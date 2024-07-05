/*
    Time Complexity: O(N), where N is total number of nodes in binary tree
    Space Complexity: O(L), where L is maximum number of nodes in the level of binary tree
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Yeh function tree create karta hai aur root node return karta hai
Node* createTree() {
    cout << "Enter the value: " << endl;
    int data;
    cin >> data;

    // Agar data -1 hai, to NULL return karo (leaf node)
    if (data == -1) {
        return NULL;
    }

    // Step 1: Node banao
    Node* root = new Node(data);
    // Step 2: Left Subtree banao
    root->left = createTree();
    // Step 3: Right Subtree banao
    root->right = createTree();

    return root;
}

// Yeh function level wise level order traversal print karta hai
void levelOrderTraversalLevelWise(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* frontNode = q.front();
        q.pop();

        if (frontNode == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << frontNode->data << " ";

            if (frontNode->left != NULL) {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL) {
                q.push(frontNode->right);
            }
        }
    }
}

// Binary Tree ka Right View print karne ka function
void printRightView(Node* root, int level, vector<int>& rightView) {
    // Base case
    if (root == NULL) {
        return;
    }

    // 1 case hum solve kar lenge
    if (level == rightView.size()) {
        rightView.push_back(root->data);
    }

    // Ab recursion solve kar lega
    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

int main() {
    Node* root = createTree();

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    int level = 0;
    vector<int> rightView;
    printRightView(root, level, rightView);

    cout << "Right view: " << endl;
    for (auto data : rightView) {
        cout << data << " ";
    }

    return 0;
}

/*
Binary Tree Inp
