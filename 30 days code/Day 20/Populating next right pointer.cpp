// Iterative approach using queue
      void bfs(Node* root){
        if(!root)return ;
        queue<Node* > q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n-1; i++){
                Node* temp = q.front();
                q.pop();
                if(temp)
                    temp->next = q.front();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            q.push(NULL);
            if(q.size() == 2)break;
            q.pop();
        }
    }
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
    
// iterative without queue
          if( ! root ) {
            return nullptr;
        } else if( ! root->left ) {
            return root;
        } else {
            auto anchor = root;
            
            while( anchor->left ) {
                auto head = anchor;
                while( head ) {
                    head->left->next = head->right;
                    if( head->next )
                        head->right->next = head->next->left;
                    head = head->next;
                }
                anchor = anchor->left;
            }
        }
        
        return root;
        
//  for loop
      Node* connect(Node* root) {
        if (!root) return nullptr;
        for (auto n = root; n->left; n = n->left)
            for (auto p = n; p; p = p->next) {
                p->left->next = p->right;
                if (p->next)
                    p->right->next = p->next->left;
            }
        return root;    
    }
    
// Recursive approach
     Node* connect(Node* root) {
        if(root == NULL)
            return root;
        root->next = NULL;
        solve(root);
        return root;
    }
    void solve(Node * root){   
        if(root == NULL)
            return ;
        if(root->left){
            root->left->next = root->right;
        }
        if(root->right){
            if(root->next == NULL)
                root->right->next = NULL;
            else 
                root->right->next = root->next->left;
        }
        solve(root->left);
        solve(root->right);
    }
