// code
  void Graph::BFS(int s) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 

// without using queue but adjacency list vector
// code
  void BFS(int curr, int N, vector<bool>& vis, 
         vector<int>& dp, vector<int>& v, 
         vector<vector<int> >& adj) 
{ 
  
    while (curr <= N) { 
  
        // Current node 
        int node = v[curr - 1]; 
        cout << node << ", "; 
  
        for (int i = 0; i < adj[node].size(); i++) { 
  
            // Adjacent node 
            int next = adj[node][i]; 
  
            if ((!vis[next]) 
                && (dp[next] < dp[node] + 1)) { 
  
                // Stores the adjacent node 
                v.push_back(next); 
  
                // Increases the distance 
                dp[next] = dp[node] + 1; 
  
                // Mark it as visited 
                vis[next] = true; 
            } 
        } 
        curr += 1; 
    } 
} 
  
// Function to print the distance 
// from source to other nodes 
void bfsTraversal( 
    vector<vector<int> >& adj, 
    int N, int source) 
{ 
    // Initially mark all nodes as false 
    vector<bool> vis(N + 1, false); 
  
    // Initialize distance array with 0 
    vector<int> dp(N + 1, 0), v; 
  
    v.push_back(source); 
  
    // Initially mark the starting 
    // source as 0 and visited as true 
    dp = 0; 
    vis = true; 
  
    // Call the BFS function 
    BFS(1, N, vis, dp, v, adj); 
} 
