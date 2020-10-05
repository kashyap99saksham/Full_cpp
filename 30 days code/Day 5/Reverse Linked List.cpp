/*
  Description : Reverse a singly linked list.
  Example     : Input: 1->2->3->4->5->NULL
                Output: 5->4->3->2->1->NULL
  Follow up:    A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

// Code with (n2) solution
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return head;
        ListNode* revhead = head;
        bool first = true;
        while(head->next != NULL){
            ListNode* curr = head;
            while(curr){
                if(curr->next->next == NULL){
                    curr->next->next = curr;
                    if(first) {revhead = curr->next; first = false;}
                    curr->next = NULL;
                }
                curr = curr->next;
            }
        }
        return revhead;
    }
    
// Code with O(n) solution.
      ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
      }
// Recursive soltion 
        ListNode* reverseList(ListNode* head) {
          if (head == NULL || head->next == NULL) return head;
          ListNode* p = reverseList(head->next);
          head->next->next = head;
          head->next = NULL;
          return p;
        }
/*
  My this approach is O(n2). in it i was trying to reverse from end. But we have O(n) soltuion also and in it we try to reverse from begining.
  And we do this by saving prev node in prev variable. In both above solution Space complexity was O(1) but in recursive solution SC is O(n) and TC O(n).
