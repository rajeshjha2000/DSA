#include<iostream>
using namespace std;
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
    ListNode* reverseList(ListNode* head) {
        // Initialize the previous node to NULL as there's no previous node for the head
        ListNode* prev = NULL;
        
        // Start with the head of the list
        ListNode* curr = head;

        // Iterate over the list until we reach the end
        while (curr != NULL) {
            // Store the next node before changing the current node's next pointer
            ListNode* nextNode = curr->next;
            
            // Reverse the link: make the current node point to the previous node
            curr->next = prev;
            
            // Move the previous pointer one step forward to the current node
            prev = curr;
            
            // Move the current pointer one step forward to the next node (stored earlier)
            curr = nextNode;
        }
        
        // After the loop, prev will be pointing to the new head of the reversed list
        return prev;
    }
};
