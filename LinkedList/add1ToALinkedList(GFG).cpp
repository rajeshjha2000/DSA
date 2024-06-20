/*/
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    // reverse list
    Node* reverseLL(Node *&head){
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // step 1: reverse linked list
        head = reverseLL(head);
        
        // step 2: add one to linked list
        Node* temp = head;
        int carry = 1;
        
        while(temp->next != NULL){
            int totalSum = temp->data + carry;
            carry = totalSum/10;
            int digit = totalSum % 10;
            
            temp->data = digit;
            temp = temp->next;
            
            if(carry==0){
                break;
            }
        }
        
        // list ke last and new node ko lag se handle karna hai
        if(carry!=0){
            int totalSum = temp->data + carry;
            carry = totalSum/10;
            int digit = totalSum % 10;
            
            temp->data = digit;
            if(carry != 0){
                Node* newNode = new Node(carry);
                temp->next = newNode;
            }
        }
        
        // step 3: reverse linked list
        head = reverseLL(head);
    }
};