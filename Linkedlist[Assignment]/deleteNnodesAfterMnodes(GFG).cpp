/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        // base case 
        if(head == NULL){
            return;
        }
        // step 1: traverse list to M position from 0th to (M-1)
        Node* tempHead = head;
        for(int i=0; i=M-1; i++){
            // tempHead agar Null psr hai
            if(tempHead == NULL){
                return;
            }
            tempHead = tempHead->next;
            
        }
        Node* MthNode = tempHead;
        
        // Mth node agar null par hai
        if(MthNode == NULL){
            return;
        }
        
        // step 2: delete N nodes;
        tempHead = MthNode->next;
        for(int i=0; i<N; i++){
            // Nth node available nhi hai
            // mtlb tempHead Null hai
            if(tempHead == NULL){
                break;
            }
            Node* temp = tempHead->next;
            delete tempHead;
            tempHead = temp;
        }
        MthNode->next = tempHead;
        
        // recursive call
        linkdelete(tempHead,M,N);
    }
};


