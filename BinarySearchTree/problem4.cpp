// Target value present or not in BST

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

// Target value found ya nahi
bool searchInBST(Node* root, int target){
    // Base Case
    if(root == NULL){
        return false;
    }

    // 1 case hum solve kar lenge
    if(target == root->data){
        return true;
    }

    bool right = false;
    bool left = false;

    // ab recursion solve kar lega
    if(target > root->data){
        right = searchInBST(root->right, target);
    }
    if(target < root->data){
        left = searchInBST(root->left, target);
    }

    return right || left;
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);

    cout<< "Enter the target:" << endl;
    int target;
    cin >> target;

    while (target != -1)
    {
        bool ans = searchInBST(root, target);
        if(ans == true){
            cout << "FOUND" << endl;
        }
        else{
            cout << "NOT FOUND" << endl;
        }
        cout<< "Enter the target:" << endl;
        cin >> target;
    }
    

    return 0;
}

/*
Binary Tree Input: 50 30 40 20 60 55 70 80 25 -1

Enter the target: 20
OUTPUT: FOUND

Enter the target: 100
OUTPUT: NOT FOUND
*/
