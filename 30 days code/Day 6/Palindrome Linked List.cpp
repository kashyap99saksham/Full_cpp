/*
  Description: Given a singly linked list, determine if it is a palindrome.
  Example 1:
      Input: 1->2
      Output: false
  Example 2:
      Input: 1->2->2->1
      Output: true
  Follow up:  Could you do it in O(n) time and O(1) space?
  
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
bool compare(ListNode* l1, ListNode* l2){
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    while(temp1 && temp2){
        if(temp1->val == temp2->val){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else return false;
    }
    if(temp1 == NULL && temp2 == NULL) return true;
    return false;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow;
        ListNode* fast;
        ListNode* slowPrev;
        ListNode* mid;
        slow = head; fast = head; slowPrev = slow; mid = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slowPrev = slow;
            slow = slow->next;
        }
        if(fast!=NULL){
            mid = slow;
            slow = slow->next;
        }
        slowPrev->next = NULL;
        slow = reverse(slow);
        bool res = compare(head, slow);
        slow = reverse(slow);
        if(mid){
            slowPrev->next = mid;
            mid->next = slow;
        }
        else
            slowPrev->next = slow;
        return res;
    }
};


/* 
    First approach is using stack but this have O(n) space complexity. Other is by recursion reach end point and pass head ref in each call when you reach end 
    start matching and increse head in last of every call this also has space (n).
    But reversing LL has O(1) space complexity and all has O(n) time complexity
*/
