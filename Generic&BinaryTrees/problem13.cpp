// bottom view of binary tree
/*
    Time Complexity: O(N), where N is total number of nodes in binary tree
    Space Complexity: O(N)
    considering a skewed tree: space complexity is O(N)
    considering non-skewed tree: space complexity is O(W), Where W is maximum width of the tree
*/

#include<iostream>
#include<queue>
#include<map>
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

// Binary Tree ka Bottom View print karne ka function
void printBottomView(Node* root) {
    map<int, int> hdToNodeMap; // <level, data>
    queue<pair<Node*, int>> q;

    // Initially root node aur level 0 ko queue mein push karo
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        // Front ko queue se fetch karo aur pop karo
        pair<Node*, int> front = q.front();
        q.pop();

        Node* frontNode = front.first;
        int level = front.second;

        // Overwrite karte hue, har level par node ka data store karo
        hdToNodeMap[level] = frontNode->data;

        // Agar root ka left node exist karta hai to queue mein push karo with level-1
        if (frontNode->left != NULL) {
            q.push(make_pair(frontNode->left, level - 1));
        }
        // Agar root ka right node exist karta hai to queue mein push karo with level+1
        if (frontNode->right != NULL) {
            q.push(make_pair(frontNode->right, level + 1));
        }
    }

    cout << "Printing Bottom View: " << endl;
    for (auto data : hdToNodeMap) {
        cout << data.second << " ";
    }
}

int main() {
    Node* root = createTree();

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    printBottomView(root);

    return 0;
}

/*
Binary Tree Input: 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 9 112 -1 -1 113 -1 -1

OUTPUT:
Level Wise Order: 
10 
20 30 
40 50 60 
70 80 9 
110 111 112 113 
Printing Bottom View: 
110 70 111 80 112 9 113 
*/
