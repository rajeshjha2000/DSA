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
    ListNode* deleteDuplicates(ListNode* head) {
        // empty list
        if(head == NULL){
            return head;
        }
        // single element list
        if(head->next == NULL){
            return head;
        }
        // non-single element list
        ListNode* temp = head;

        while(temp != NULL){
            if(temp->next != NULL && temp->val == temp->next->val){
                // remove duplicates
                ListNode* nextNode = temp->next;
                temp->next = nextNode->next;
                nextNode->next = NULL;
                delete nextNode;
            }
            else{
                // temp ko aage bhej do
                temp = temp ->next;
            }
        }
        // yahan galti ho skti hai , galti se hum temp return kar skta hain
        return head;
    }
};