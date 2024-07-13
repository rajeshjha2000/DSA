// Convert Sorted Double Linked List into BST

/*
Time Complexity: O(N)
Space Complexity: O(log N) (due to the recursive call stack)
Where N is number of nodes of DLL
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

// Level order traversal in level wise
void levelOrderTraversalLevelWise(Node* root){
    queue<Node*> q;  // Queue ka use karke level order traversal karenge
    q.push(root);  // Root node ko queue mein daalenge
    q.push(NULL);  // Level separator ke liye NULL daalenge

    while(!q.empty()){
        Node* frontNode = q.front();  // Queue ke front node ko nikalenge
        q.pop();
        
        if(frontNode == NULL){  // Agar front node NULL hai toh level change ho gaya
            cout<<endl;
            if(!q.empty()){  // Agar queue empty nahi hai toh naya level start karenge
                q.push(NULL);
            }
        }
        else{
            cout<< frontNode->data << " ";  // Front node ka data print karenge

            if(frontNode->left != NULL){  // Agar left child exist karta hai toh queue mein daalenge
                q.push(frontNode->left);
            }
            if(frontNode->right != NULL){  // Agar right child exist karta hai toh queue mein daalenge
                q.push(frontNode->right);
            }
        }
    }
}

Node* convertDLLtoBST(Node* &head, int n){
    // Base case
    // Agar head NULL hai ya n <= 0 hai, toh NULL return karo
    if(head == NULL || n <= 0){
        return NULL;
    }

    // Inorder traversal (Left, Node, Right)
    // Left subtree ko convert karenge
    Node* leftST = convertDLLtoBST(head, n/2);

    // Node ko process karenge
    Node* root = head;  // Current node ko root banayenge
    root->left = leftST;  // Left subtree ko current node ke left mein daalenge
    // Head ko update karenge
    head = head->right;  // Head ko right child pe move karenge

    // Right subtree ko convert karenge
    Node* rightST = convertDLLtoBST(head, (n - n/2 - 1));  // Right subtree ko current node ke right mein daalenge
    root->right = rightST;

    return root;  // Root node return karenge
}

void printDLL(Node* head){
    // Double Linked List ko print karenge
    Node* temp = head;
    while (temp != NULL)  // Jab tak temp NULL nahi hota
    {
        cout<< temp->data << " ";  // Temp ka data print karenge
        temp = temp->right;  // Temp ko right child pe move karenge
    }
    cout<<endl;    
}

int main() {

    Node* first = new Node(10);  // Pehla node banayenge
    Node* second = new Node(20);  // Dusra node banayenge
    Node* third = new Node(30);  // Teesra node banayenge

    first->right = second;  // Pehla node ke right mein dusra node
    second->left = first;  // Dusra node ke left mein pehla node
    second->right = third;  // Dusra node ke right mein teesra node
    third->left = second;  // Teesra node ke left mein dusra node

    Node* head = first;  // Head ko pehla node banayenge
    cout << "Sorted Double Linked List: " << endl;
    printDLL(head);  // Double Linked List ko print karenge

    int n = 3;  // Number of nodes in DLL
    Node* root = convertDLLtoBST(head, n);  // DLL ko BST mein convert karenge
    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);  // Level order traversal karenge

    return 0;
}

/*
Example 1:
Sorted Double Linked List: 
10<->20<->30

Level Wise Order: 
    20
    / \
   10  30
*/
