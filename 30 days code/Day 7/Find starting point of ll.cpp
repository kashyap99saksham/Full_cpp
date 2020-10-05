    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (fast == NULL || fast->next == NULL)return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }while (slow != fast);
        if(slow == head)return head;
        fast = head;
        while(fast->next != slow->next){
            fast = fast->next;
            slow = slow->next;
        }
        return slow->next;
    }
