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
    // Function to detect if a cycle is present in a linked list
    bool hasCycle(ListNode *head) {
        // Create a hash table to store nodes we have seen
        map<ListNode*, bool> table;

        // Initialize a temporary pointer to traverse the list
        ListNode* temp = head;

        // Traverse the list
        while(temp != NULL) {
            // Check if the current node is already in the hash table
            if(table[temp] == false) {
                // Mark the current node as seen
                table[temp] = true;
            } else {
                // If the current node is already marked as seen, a cycle is present
                return true;
            }
            // Move to the next node
            temp = temp->next;
        }
        // If we reach the end of the list, no cycle is present
        return false;
    }
};
-------------------------------------------------------------------------------------------
// 2nd method 
bool hasCycle(ListNode *head) {
    // step 1
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
            return true;
        }
        // loop is not present
    } return false;
    
}