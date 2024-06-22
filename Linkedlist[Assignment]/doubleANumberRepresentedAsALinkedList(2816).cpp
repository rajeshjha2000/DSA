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
    // Recursive function to process the linked list and handle carry-over
    void solve(ListNode* head, int& carry) {
        // Base case: if the current node is null, return
        if (!head) return;

        // Recursive call to process the next node
        solve(head->next, carry);

        // Double the current node's value and add the carry
        int product = head->val * 2 + carry;

        // Update the current node's value to the last digit of the product
        head->val = product % 10;

        // Update the carry to be the remaining digits of the product
        carry = product / 10;
    }

    // Function to double the values in the linked list
    ListNode* doubleIt(ListNode* head) {
        // Initialize carry to 0
        int carry = 0;

        // Call the recursive function to process the list
        solve(head, carry);

        // If there's a carry left after processing all nodes, create a new head node
        if (carry) {
            ListNode* carryNode = new ListNode(carry);
            carryNode->next = head;
            head = carryNode;
        }

        // Return the updated head of the list
        return head;
    }
};
