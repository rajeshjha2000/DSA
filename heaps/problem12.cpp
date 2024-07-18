// Convert Given Combination of CBT and BST into a Valid Max Heap (GFG)

/*
Time complexity: O(N)
Space complexity: O(H+N)
Where N and H are the number of nodes and height of the binary tree respectivily.
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* inserIntoBST(Node* root, int data){
    if(root == NULL){  // Agar root NULL hai, to naya node create karte hain
        Node* root = new Node(data);
        return root;
    }
    if(data > root->data){  // Agar data root se bada hai, to right subtree me insert karte hain
        root->right = inserIntoBST(root->right, data);
    }
    else{  // Agar data root se chota hai, to left subtree me insert karte hain
        root->left = inserIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root){
    cout<< "Enter Data: " << endl;
    int data;
    cin >> data;
    while (data != -1)  // -1 aane tak data lete hain aur tree create karte hain
    {
        root = inserIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversalLevelWise(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // NULL ko queue me push karte hain taaki level end ko identify kar sakein

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        if(frontNode == NULL){  // Agar NULL mila to ek level khatam ho gaya
            cout<<endl;
            if(!q.empty()){  // Agar queue khali nahi hai to NULL ko fir se push karte hain
                q.push(NULL);
            }
        }
        else{
            cout<< frontNode->data << " ";  // Current node ka data print karte hain
            if(frontNode->left != NULL){
                q.push(frontNode->left);  // Left child ko queue me push karte hain
            }
            if(frontNode->right != NULL){
                q.push(frontNode->right);  // Right child ko queue me push karte hain
            }
        }
    }
}

void storeInorderTraversal(Node* root, vector<int> &in){
    if(root == NULL){  // Agar root NULL hai to return karte hain
        return;
    }
    storeInorderTraversal(root->left, in);  // Left subtree ka inorder traversal store karte hain
    in.push_back(root->data);  // Current node ka data vector me store karte hain
    storeInorderTraversal(root->right, in);  // Right subtree ka inorder traversal store karte hain
}

void replaceWithPostorder(Node* root, vector<int> in, int &index){
    if(root == NULL){  // Agar root NULL hai to return karte hain
        return;
    }
    replaceWithPostorder(root->left, in, index);  // Left subtree ko postorder me replace karte hain
    replaceWithPostorder(root->right, in, index);  // Right subtree ko postorder me replace karte hain
    root->data = in[index];  // Current node ka data replace karte hain
    index++;
}

Node* convertBSTIntoMaxHeap(Node* root){
    vector<int> inorder;  // Inorder traversal ko store karne ke liye vector
    storeInorderTraversal(root, inorder);  // Inorder traversal store karte hain

    int index = 0;
    replaceWithPostorder(root, inorder, index);  // Inorder traversal ko postorder traversal se replace karte hain

    return root;
}

int main(){
    Node* root = NULL;
    createBST(root);  // BST create karte hain

    cout << "CBT+BST: " << endl;
    levelOrderTraversalLevelWise(root);  // Level order traversal print karte hain

    root = convertBSTIntoMaxHeap(root);  // BST ko Max Heap me convert karte hain
    cout << "CBT+MAX HEAP: " << endl;
    levelOrderTraversalLevelWise(root);  // Level order traversal print karte hain

    return 0;
}

/*
Binary Tree Input: 100 50 150 40 60 110 200 20 -1 

OUTPUT:

CBT+BST: 
100 
50 150 
40 60 110 200 
20 

CBT+MAX HEAP: 
200 
60 150 
40 50 100 110 
20 

*/