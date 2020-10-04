// There are many approaches first is brute force for every node in list1 traverse in list2 and check if value of both matches anywhere O(mn) solution.
// Another is using hashtable traverse list1 and save value in hash then traverse list2 and check for matches in hash O(m+n) and space O(m) or (n).
// And other is below implemented first find which is short and by how much then traverse the long for amount of long it is from short and then start matching.

//  Code
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int count = 0;
        bool Aisbig = false;
        while(tempA != NULL && tempB != NULL){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        while(tempA != NULL){
            tempA = tempA->next;
            count++;
            Aisbig = true;
        }
        while(tempB != NULL){
            tempB = tempB->next;
            count++;
        }
        tempA = headA;
        tempB = headB;
        if(Aisbig){
            while(count-- && tempA != NULL){
                tempA = tempA->next;                
            }
        }
        else{
            while(count-- && tempB != NULL)
                tempB = tempB->next;
        }
        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
  }
  
// Same implementation but in less line of code

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA, *tempB = headB;
        
        if (tempA == NULL || tempB == NULL) return NULL; //if list is null at start
        
        while (tempA || tempB) {
            if (tempA == NULL) tempA = headB; //if tempA reaches end of list A
            if (tempB == NULL) tempB = headA; //if tempB reaches end of list B
            if (tempA == tempB) return tempA; //if intersection is detected
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return NULL;
    }
