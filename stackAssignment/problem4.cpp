// Problem 4: Next Greater Node in Linked List [LC-1019]

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll; // Vector to store the values from the linked list

        // Traverse the linked list and store values in the vector
        while (head) {
            ll.push_back(head->val);
            head = head->next;
        }

        stack<int> st; // Stack to keep track of indices of elements
        vector<int> ans(ll.size(), 0); // Initialize result vector with 0s

        // Traverse the values stored in the vector
        for (int i = 0; i < ll.size(); i++) {
            // While stack is not empty and current value is greater than value at stack's top index
            while (!st.empty() && ll[i] > ll[st.top()]) {
                int index = st.top(); // Index of the element that has a next greater element
                st.pop(); // Pop the index
                ans[index] = ll[i]; // Update the result for this index with the current value
            }
            st.push(i); // Push current index onto the stack
        }

        return ans; // Return the result vector
    }
};

