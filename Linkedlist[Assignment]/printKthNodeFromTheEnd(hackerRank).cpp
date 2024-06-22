/*
 * Complete the 'getNode' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER positionFromTail
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void solve(SinglyLinkedListNode* head, int &pos, int &ans){
    // base case 
    if (head == 0) {
     return;
    }
    // step 1: traverse the list from head to tail-> recursion
    solve(head->next,pos,ans);
    
    // step 2: traverse the list from tail to (pos ==0)
    
    if (pos ==0) {
     ans = head->data;
    }
    pos--;
}
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
// step 3: return ans
int ans = -1;
solve(llist,positionFromTail,ans);
return ans;
}