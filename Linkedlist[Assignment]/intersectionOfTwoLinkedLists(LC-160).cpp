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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;

        while(listA->next != NULL && listB->next != NULL){
            if(listA == listB){
                // agar listA and listB equal length ki hai
                // iska matlab wo yahin se intersect node return kar degi
                return listA;
            }
            listA = listA->next;
            listB = listB->next;
        }
        // mai yahan tak tabhi pahuncha hu 
        // jab listA and listB ki length equal nhi hai
        if(listA->next == NULL){
            //ListB is bigger
            // we need to find the length of listB

            int listBLength = 0;
            while(listB->next != 0){
                listBLength++;
                listB = listB->next;
            }
            // in starting, set headB at right node 
            // to get the intersection node
            while(listBLength--){
                headB = headB->next;
            }
        }
        if(listB->next == NULL){
            //ListA is bigger
            // we need to find the length of listA

            int listALength = 0;
            while(listA->next != 0){
                listALength++;
                listA = listA->next;
            }
            // in starting, set headA at right node 
            // to get the intersection node
            while(listALength--){
                headB = headA->next;
            }
        }
        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        // Missing return statement here
        return headA; // or headB
    }
};
