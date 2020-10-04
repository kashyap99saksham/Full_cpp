/*
  Description : Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
  Example
         Input: 1->2->4, 1->3->4
         Output: 1->1->2->3->4->4
*/
//Code
      ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode* temp = &head;
        head.next = NULL;
        if(l1 == NULL)
            temp->next = l1;
        if(l2 == NULL)
            temp->next = l2;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                temp->next = l2;
                l2 = l2->next;
            }
            else{
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
            cout<<temp->val;
        }
        if(l1 != NULL)
            temp->next = l1;
        if(l2 != NULL)
            temp->next = l2;
        return head.next;
    }
