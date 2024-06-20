#include<iostream>
using namespace std;  

  void removeLoop(Node* head){
    // step 01: find loop (already done)
    // step 02: find starting point of loop

    slow = head;

    //slow and fast -> 1 step
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // save starting point 
    NOde* startPoint = slow;

    // step 3 : remove loop
    Node* temp = fast;
    while (temp->next != startPoint)
    {
        temp = temp->next;
    }
    
    // last node ke next ko null krdo
    temp->next = NULL;
    
  }