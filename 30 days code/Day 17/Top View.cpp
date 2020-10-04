// Approach is to do level order traversal and print value coming first
// code
    void topview(Node* root) 
{ 
    if(root==NULL) 
       return; 
     queue<Node*>q; 
     map<int,int> m;  
     int hd=0; 
     root->hd=hd; 
       
     // push node and horizontal distance to queue 
    q.push(root); 
      
    cout<< "The top view of the tree is : \n"; 
      
    while(q.size()) 
    { 
        hd=root->hd; 
          
        // count function returns 1 if the container  
        // contains an element whose key is equivalent  
        // to hd, or returns zero otherwise. 
        if(m.count(hd)==0)   
        m[hd]=root->data; 
        if(root->left) 
        { 
            root->left->hd=hd-1; 
            q.push(root->left); 
        } 
        if(root->right) 
        { 
            root->right->hd=hd+1; 
            q.push(root->right); 
        } 
        q.pop(); 
        root=q.front(); 
        
    } 
      
      
      
     for(auto i=m.begin();i!=m.end();i++) 
    { 
        cout<<i->second<<" "; 
    } 
      
} 
  
// Approach without queue using 2 variable HD and VD
// code
  void fillMap(Node* root,int d,int l,map<int,pair<int,int>> &m){ 
    if(root==NULL) return; 
  
    if(m.count(d)==0){ 
        m[d] = make_pair(root->data,l); 
    }else if(m[d].second>l){ 
        m[d] = make_pair(root->data,l); 
    } 
  
    fillMap(root->left,d-1,l+1,m); 
    fillMap(root->right,d+1,l+1,m); 
} 
  
// function should print the topView of 
// the binary tree 
void topView(struct Node *root){ 
  
    //map to store the pair of node value and its level  
    //with respect to the vertical distance from root.  
    map<int,pair<int,int>> m; 
  
    //fillmap(root,vectical_distance_from_root,level_of_node,map) 
    fillMap(root,0,0,m); 
  
    for(auto it=m.begin();it!=m.end();it++){ 
        cout << it->second.first << " "; 
    } 
} 
