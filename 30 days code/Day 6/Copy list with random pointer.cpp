/*
  Descripiton : A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
                Return a deep copy of the list.
                The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
                val: an integer representing Node.val
                random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
*/

// Code
      Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* temp = head;
        while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            if(temp->random == NULL) temp->next->random = NULL;
            else
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node* temp2 = head->next;
        Node* head2 = temp2;
        while(temp2 && temp2->next != NULL){
            temp->next = temp->next->next;
            temp2->next = temp2->next->next;
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp->next = NULL;
        return head2;
        
    }
    
// there are 2 approaches for this first is make duplicate list simple and store random pointer to hasmap and also check for duplicate values and other is implemented above
