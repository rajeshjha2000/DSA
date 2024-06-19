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
    // Function to calculate the length of the linked list
    int getLength(ListNode* head) {
        int length = 0;       // Initialize length counter to 0
        ListNode* temp = head; // Use temp pointer to traverse the list
        
        // Traverse the list until the end (NULL)
        while (temp != NULL) {
            length++;        // Increment the length counter
            temp = temp->next; // Move to the next node
        }
        
        return length;       // Return the total length of the list
    }

    // Function to find the middle node of the linked list
    ListNode* middleNode(ListNode* head) {
        int n = getLength(head); // Get the total length of the list
        int position = n / 2 + 1; // Calculate the position of the middle node (1-based index)
        int currPos = 1;         // Initialize current position counter to 1
        ListNode* temp = head;   // Use temp pointer to traverse the list
        
        // Traverse the list until reaching the middle node
        while (currPos != position) {
            currPos++;         // Increment the current position counter
            temp = temp->next; // Move to the next node
        }
        
        return temp;           // Return the middle node
    }
};
-------------------------------------------------------------------------
// 2nd way to solve the problem
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
    // Function to calculate the length of the linked list
    int getLength(ListNode* head) {
        int length = 0;         // Initialize length counter to 0
        ListNode* temp = head;  // Use temp pointer to traverse the list
        
        // Traverse the list until the end (NULL)
        while (temp != NULL) {
            length++;           // Increment the length counter
            temp = temp->next;  // Move to the next node
        }
        
        return length;          // Return the total length of the list
    }

    // Function to find the middle node of the linked list using the two-pointer technique
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;  // Initialize slow pointer to the head of the list
        ListNode* fast = head;  // Initialize fast pointer to the head of the list
        
        // Traverse the list with fast pointer moving twice as fast as slow pointer
        while (fast != NULL) {
            fast = fast->next;  // Move fast pointer one step ahead
            if (fast != NULL) { // Check if fast pointer has not reached the end
                fast = fast->next; // Move fast pointer another step ahead
                slow = slow->next; // Move slow pointer one step ahead
            }
        }
        
        // When fast pointer reaches the end, slow pointer will be at the middle
        return slow;  // Return the slow pointer which is now at the middle node
    }
};

};

----------------------------------------------------------------------------------------------------------------------------------------------------------------
//one more way to handle middle node case in even nodes condition
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
    // Function to calculate the length of the linked list
    int getLength(ListNode* head) {
        int length = 0;         // Initialize length counter to 0
        ListNode* temp = head;  // Use temp pointer to traverse the list
        
        // Traverse the list until the end (NULL)
        while (temp != NULL) {
            length++;           // Increment the length counter
            temp = temp->next;  // Move to the next node
        }
        
        return length;          // Return the total length of the list
    }

    // Function to find the middle node of the linked list using the two-pointer technique
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;  // Initialize slow pointer to the head of the list
        ListNode* fast = head;  // Initialize fast pointer to the head of the list
        
        // Traverse the list with fast pointer moving twice as fast as slow pointer
        while (fast->next != NULL) {
            fast = fast->next;  // Move fast pointer one step ahead
            if (fast->next != NULL) { // Check if fast pointer has not reached the end
                fast = fast->next; // Move fast pointer another step ahead
                slow = slow->next; // Move slow pointer one step ahead
            }
        }
        
        // When fast pointer reaches the end, slow pointer will be at the middle
        return slow;  // Return the slow pointer which is now at the middle node
    }
};
