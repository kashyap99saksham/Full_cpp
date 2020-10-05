/*
  Approach is to perform BFS and to maintain which node is visited and not we maintain a hash with key as original node and value as clone of that node
  While visiting the neighboring vertices of a node u get the corresponding cloned node for u , let’s call that cloneNodeU , 
  now visit all the neighboring nodes for u and for each neighbor find the corresponding clone node(if not found create one) 
  and then push into the neighboring vector of cloneNodeU node.
  How to verify if the cloned graph is a correct?
  Do a BFS traversal before and after the cloning of graph. In BFS traversal display the value of a node along with its address/reference.
  Compare the order in which nodes are displayed, if the values are same but the address/reference is different for both the traversals than the cloned graph is correct.
  Below approach is only for single component undirected graph
*/

// code
  // A function which clones a Graph and 
// returns the address to the cloned 
// src node 
GraphNode *cloneGraph(GraphNode *src) 
{ 
    //A Map to keep track of all the 
    //nodes which have already been created 
    map<GraphNode*, GraphNode*> m; 
    queue<GraphNode*> q; 
  
    // Enqueue src node 
    q.push(src); 
    GraphNode *node; 
  
    // Make a clone Node 
    node = new GraphNode(); 
    node->val = src->val; 
  
    // Put the clone node into the Map 
    m[src] = node; 
    while (!q.empty()) 
    { 
        //Get the front node from the queue 
        //and then visit all its neighbours 
        GraphNode *u = q.front(); 
        q.pop(); 
        vector<GraphNode *> v = u->neighbours; 
        int n = v.size(); 
        for (int i = 0; i < n; i++) 
        { 
            // Check if this node has already been created 
            if (m[v[i]] == NULL) 
            { 
                // If not then create a new Node and 
                // put into the HashMap 
                node = new GraphNode(); 
                node->val = v[i]->val; 
                m[v[i]] = node; 
                q.push(v[i]); 
            } 
  
            // add these neighbours to the cloned graph node 
            m[u]->neighbours.push_back(m[v[i]]); 
        } 
    } 
  
    // Return the address of cloned src Node 
    return m[src]; 
} 

