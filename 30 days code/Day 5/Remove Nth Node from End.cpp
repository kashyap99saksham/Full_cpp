/*
  Description :  Given a linked list, remove the n-th node from the end of list and return its head.
  Example :      Given linked list: 1->2->3->4->5, and n = 2.
                 After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note  :        Given n will always be valid.
  Follow up :    Could you do this in one pass?
*/
// code
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* front = &dummy;
        ListNode* back = front;
        n++;
        while(n--)front = front->next;
        while(front != NULL){
            front = front->next;
            back = back->next;
        }
        back->next = back->next->next;
        return dummy.next;
    }
    
// Basic approach is to go through list twice count node in first iteration and remove n-kth in 2nd iteration. and other basic is recursive solution.
