 Node* flatternUtil(Node* node){
    if(node == NULL)return node;
    Node* temp = node;
    while(1){
        // if(temp->next == NULL && temp->child == NULL) return temp;
        while(temp->child == NULL && temp->next != NULL)  temp = temp->next;
        if(temp->next == NULL && temp->child == NULL) return temp;
        if(temp->next == NULL && temp->child != NULL){
            temp->next = temp->child;
            temp->child = NULL;
            temp->next->prev = temp;
            temp = temp->next;
            continue;
        }
        // if(temp->next == NULL) return temp;
        Node* nxt = temp->next;
        temp->next = temp->child;
        temp->child = NULL;
        Node* link = flatternUtil(temp->next);
        link->next = nxt;
        link->next->prev = link;
        temp->next->prev = temp;
        temp = link->next;
    }
}
