// boundary treversal of binary tree
/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is number of nodes in binary tree
*/

#include<iostream>
#include<queue>
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

// Binary Tree ka Left Boundary print karne ka function
void printLeftBoundary(Node* root) {
    // Base Case
    if (root == NULL) {
        return;
    }

    // First Left Leaf Node aane par function se bahar ho jaao
    if (root->left == NULL && root->right == NULL) {
        return;
    }

    cout << root->data << " ";

    if (root->left != NULL) {
        printLeftBoundary(root->left);
    } else if (root->right != NULL) {
        printLeftBoundary(root->right);
    }
}

// Binary Tree ka Leaf Nodes print karne ka function
void printLeafBoundary(Node* root) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Jab leaf node aayega tabhi print karna hai
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

// Binary Tree ka Right Boundary print karne ka function
void printRightBoundary(Node* root) {
    // Base case
    if (root == NULL) {
        return;
    }

    // First Right Leaf Node aane par function se bahar ho jaao
    if (root->left == NULL && root->right == NULL) {
        return;
    }

    if (root->right != NULL) {
        printRightBoundary(root->right);
    } else if (root->left != NULL) {
        printRightBoundary(root->left);
    }

    cout << root->data << " ";
}

// Binary Tree ka Boundary Traversal print karne ka function
void boundaryTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    // Left Boundary
    if (root->left != NULL) {
        printLeftBoundary(root->left);
    }

    // Leaf Nodes
    printLeafBoundary(root);

    // Right Boundary
    if (root->right != NULL) {
        printRightBoundary(root->right);
    }
}

int main() {
    Node* root = createTree();

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    cout << "Boundary Traversal: " << endl;
    boundaryTraversal(root);

    return 0;
}

/*
Binary Tree Input: 
Example 1: 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

OUTPUT:
Level Wise Order: 
10 
20 30 
40 50 60 
70 80 90 
110 111 112 113 
Boundary Traversal: 
10 20 40 110 111 80 112 113 90 60 30 

Example 2: 10 20 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

OUTPUT:
Level Wise Order: 
10 
20 30 
50 60 
70 80 90 
110 111 112 113 
Boundary Traversal: 
10 20 50 70 110 111 80 112 113 90 60 30 

Example 3: 10 20 30 40 -1 -1 -1 -1 -1
Level Wise Order: 
10 
20 
30 
40 
Boundary Traversal: 
10 20 30 40 30 20 

Example 4: 10 -1 20 -1 30 -1 40 -1 -1
Level Wise Order: 
10 
20 
30 
40 
Boundary Traversal: 
10 20 30 40 30 20 
*/
