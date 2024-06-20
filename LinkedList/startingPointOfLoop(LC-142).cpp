#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // check for loop
        ListNode* slow = head;
    ListNode* fast = head;

    // step 2 
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // check loop
        if (slow == fast)
        {
            break;
        }
    } 
    if(fast == NULL){
        // no cycle present 
        return NULL;
    }
    
    // yaha pahuncha iska matlb slow and fast meet kr chuke hai
    slow = head;

    // slow and fast -> 1 step
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    // return starting point
    return slow;
    }
};