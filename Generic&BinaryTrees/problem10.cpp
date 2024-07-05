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

// Binary Tree ka Left View print karne ka function
void printLeftView(Node* root, int level, vector<int>& leftView) {
    // Base case
    if (root == NULL) {
        return;
    }

    // 1 case hum solve kar lenge
    if (level == leftView.size()) {
        leftView.push_back(root->data);
    }

    // Ab recursion solve kar lega
    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

int main() {
    Node* root = createTree();

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    int level = 0;
    vector<int> leftView;
    printLeftView(root, level, leftView);

    cout << "Left view: " << endl;
    for (auto data : leftView) {
        cout << data << " ";
    }

    return 0;
}

/*
Binary Tree Input: 10 15 25 -1 45 65 -1 -1 96 -1 -1 -1 11 16 -1 -1 -1 

OUTPUT:
Level Wise Order: 
10 
15 11 
25 16 
45 
65 96 
Left view: 
10 15 25 45 65 
*/
