/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   int getLength(ListNode* head){
    ListNode* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
   }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        int len = getLength(head);
        if(len<k){
            // we can handle
            // empty and single element list using this condition
            return head;
        }
        // 1 case hum solve krenge
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;
        int position = 0;

        while(position<k){
            nextNode = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nextNode;
            position++;

        }
        // ab recursion solve kr lega
        ListNode* recursionKaAns = NULL;
        if(nextNode != NULL){
            recursionKaAns = reverseKGroup(nextNode, k);

            // catch 1:
            head->next = recursionKaAns;
        }
        // catch 2 :
        return prev;
    }
};