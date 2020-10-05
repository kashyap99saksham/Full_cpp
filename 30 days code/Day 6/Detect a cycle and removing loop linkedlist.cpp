/*
  Description : You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present. 
  Expected time complexity : O(n)
  Expected auxiliary space : O(1)
  
*/

// Code

  void removeLoop(Node* head){
    if (head == NULL || head->next == NULL)return;
        Node* slow = head;
        Node* fast = head;
        do {
            if (fast == NULL || fast->next == NULL)return ;
            slow = slow->next;
            fast = fast->next->next;
        }while (slow != fast);
        if(slow == head){
            while(slow->next != head)slow = slow->next;
            slow->next = NULL;
            return;
        }
        else{
        fast = head;
        // slow = slow;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = NULL;
        return;
        }
  }
