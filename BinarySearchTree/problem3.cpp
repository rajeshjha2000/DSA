// Min and Max value in BST

/*
    Time complexity:
    Skewed BST: O(N) ya O(H) worst case mein
    Balanced BST: O(log N) average case mein

    Space Complexity: O(H)
    Worst case mein: H = O(N)
    Average case mein: H = O(log N) 

    Yahan H BST ki height hai aur N BST mein nodes ki sankhya hai
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
        // Right Sub Tree mein insert karo
        root->right = inserIntoBST(root->right, data);
    }
    else{
        // Left Sub Tree mein insert karo
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

// BST ka min value
Node* minValue(Node* root){
    if(root == NULL){
        // BST ka koi min value nahi hai
        return NULL;
    }

    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

// BST ka max value
Node* maxValue(Node* root){
    if(root == NULL){
        // BST ka koi max value nahi hai
        return NULL;
    }

    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    Node* minNode = minValue(root);
    Node* maxNode = maxValue(root);

    if(minNode == NULL){
        cout<< "No Min Value" << endl;
    }
    else{
        cout<< "Min Value: " << minNode->data << endl;
    }

    if(maxNode == NULL){
        cout<< "No Max Value" << endl;
    }
    else{
        cout<< "Max Value: " << maxNode->data << endl;
    }

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
Min Value: 20
Max Value: 80
*/
