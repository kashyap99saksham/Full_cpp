/*
  Description :   Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
                  k is a positive integer and is less than or equal to the length of the linked list. 
                  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
  Example     :   Given this linked list: 1->2->3->4->5
                  For k = 2, you should return: 2->1->4->3->5
                  For k = 3, you should return: 3->2->1->4->5
  Note        :   Only constant extra memory is allowed. You may not alter the values in the list's nodes, only nodes itself may be changed.
*/
// Code

 ListNode* reverse(ListNode* head){
    ListNode* curr;
    ListNode* prev;
    ListNode* nxt = NULL;
    curr = head; prev = NULL;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newhead;
        ListNode* temp = head;
        ListNode* nxt;
        ListNode* begin;
        ListNode* prev = temp;
        bool first = true;
        while(temp){
            begin = temp;
            int count = k-1;
            while(count-- && temp != NULL){
                temp = temp->next;
            }
            if(temp == NULL) break;
            nxt = temp->next;
            temp->next = NULL;
            temp = reverse(begin);
            if(first){
                newhead = temp;
                first = false;
            }
            else 
                prev->next = temp;
            temp = begin;
            temp->next = nxt;
            prev = temp;
            temp = temp->next;
        }
        return newhead;
    }
