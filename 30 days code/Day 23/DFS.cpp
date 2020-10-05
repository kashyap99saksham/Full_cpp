/*
  Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. 
  The only catch here is, unlike trees, graphs may contain cycles, a node may be visited twice. 
  To avoid processing a node more than once, use a boolean visited array.
  O(V+E) O(V)
*/
// code
  void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 

/* 
  Handling Disconnected Graph
    Solution: This will happen by handling a corner case.
    The above code traverses only the vertices reachable from a given source vertex. 
    All the vertices may not be reachable from a given vertex as in the case of a Disconnected graph. 
    To do complete DFS traversal of such graphs, run DFS from all unvisited nodes after a DFS.
    The recursive function remains the same.
*/
// code
  void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// The function to do DFS traversal. It uses recursive DFSUtil() 
void Graph::DFS() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to print DFS traversal 
    // starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            DFSUtil(i, visited); 
} 
