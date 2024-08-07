// create binary search tree

/*
    Time Complexity: 
    In Unbalanced BST, O(N)
    In balanced BST, O(log N)

    Overall time complexity:
    Worst Case: O(N)
    Average Case: O(N log N)
    Where N is number of nodes in binary search tree

    Space Complexity: O(H), Where H is height of BST
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Node class jo ek node ko represent karta hai
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        // Node ka constructor
        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

// BINARY SEARCH TREE CREATE KARNA
Node* inserIntoBST(Node* root, int data){
    // Jab root null ho tab pehla node create karo
    if(root == NULL){
        Node* root = new Node(data);
        return root;
    }

    // Pehla node ke liye nahi
    if(data > root->data){
        // Right Sub Tree me insert karo
        root->right = inserIntoBST(root->right, data);
    }
    else{
        // Left Sub Tree me insert karo
        root->left = inserIntoBST(root->left, data);
    }

    return root;
}

// BST create karne ke liye function
void createBST(Node* &root){
    cout<< "Enter Data: " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = inserIntoBST(root, data);
        cin >> data;
    }
    
}

// Level order traversal, level wise
void levelOrderTraversalLevelWise(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        
        if(frontNode == NULL){
            cout<<endl;
            if(!q.empty()){ 
                q.push(NULL);
            }
        }
        else{
            cout<< frontNode->data << " ";

            if(frontNode->left != NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right != NULL){
                q.push(frontNode->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    return 0;
}

/*
Binary Tree Input: 50 30 40 20 60 55 70 80 25 -1

OUTPUT:
Level Wise Order: 
50 
30 60 
20 40 55 70 
25 80 
*/
