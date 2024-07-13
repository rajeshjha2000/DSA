// Convert BST into Sorted Double Linked List

/*
Time Complexity: O(N)
Space Complexity: O(H)
Where N is number of nodes of BST and H is height of BST
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

Node* bstFromInorder(int inorder[], int start, int end){
    // Base case 
    // Agar start index end index se bada hai, toh NULL return karo
    if(start > end){
        return NULL;
    }

    // Ek case ko solve kar lete hain
    int mid = (start + end) / 2;  // Mid point calculate karenge
    int element = inorder[mid];  // Mid point ka element nikalenge
    Node* root = new Node(element);  // Naya node banayenge

    // Ab recursion se left aur right subtree banate hain
    root->left = bstFromInorder(inorder, start, mid - 1);  // Left subtree banayenge
    root->right = bstFromInorder(inorder, mid + 1, end);  // Right subtree banayenge
    
    return root;  // Root node return karenge
}

void convertBSTtoDLL(Node* root, Node* &head){
    // Base case
    // Agar root NULL hai, toh return karo
    if(root == NULL){
        return;
    }

    // Reverse Inorder Traversal
    // Right subtree ko traverse karo
    convertBSTtoDLL(root->right, head);

    // Node ko process karo
    root->right = head;  // Current node ka right child ko head se link karo
    if(head != NULL){
        head->left = root;  // Agar head NULL nahi hai toh head ka left child current node ko banao
    }
    // Head ko update karo
    head = root;  // Head ko current node banao

    // Left subtree ko traverse karo
    convertBSTtoDLL(root->left, head);
}

void printDLL(Node* head){
    // Double Linked List ko print karo
    Node* temp = head;
    while (temp != NULL)  // Jab tak temp NULL nahi hota
    {
        cout<< temp->data << " ";  // Temp ka data print karo
        temp = temp->right;  // Temp ko right child pe move karo
    }
    cout<<endl;    
}

int main(){

    int inorder[] = {5, 50, 60, 100, 200, 300};  // Inorder array diya hua hai
    int size = 6;  // Array ka size
    int start = 0;  // Starting index
    int end = size - 1;  // Ending index
    
    Node* root = bstFromInorder(inorder, start, end);  // BST banate hain inorder array se
    cout << "Level Wise Order: " << endl;
    levelOrderTraversalLevelWise(root);  // Level order traversal karte hain

    Node* head = NULL;  // DLL ka head NULL se initialize karte hain
    convertBSTtoDLL(root, head);  // BST ko DLL mein convert karte hain
    cout << "Sorted Double Linked List: " << endl;
    printDLL(head);  // DLL ko print karte hain

    return 0;
}

/*

Example 1:
In Order: [10 20 30 40 50 60 70 80]
Level Wise Order: 
60 
5 200 
50 100 300 
Sorted Double Linked List: 
5 50 60 100 200 300 
*/
