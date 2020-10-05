/*
  Decription :  
  
  
*/

// Code
      ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
      }
      
// Always check you order like here if you check fast->next first then you will have error so check fast first then fast->next.
