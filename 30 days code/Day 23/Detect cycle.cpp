/*
  1st is for undirected graph
  Approach: Run a DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. 
  There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is joining a node to itself (self-loop) or 
  one of its ancestor in the tree produced by DFS.
  To find the back edge to any of its ancestor keep a visited array and if there is a back edge to any visited node then there is a loop and return true
*/
// code
  bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
  { 
      // Mark the current node as visited 
      visited[v] = true; 

      // Recur for all the vertices adjacent to this vertex 
      list<int>::iterator i; 
      for (i = adj[v].begin(); i != adj[v].end(); ++i) 
      { 
          // If an adjacent is not visited, then recur for that adjacent 
          if (!visited[*i]) 
          { 
             if (isCyclicUtil(*i, visited, v)) 
                return true; 
          } 

          // If an adjacent is visited and not parent of current vertex, 
          // then there is a cycle. 
          else if (*i != parent) 
             return true; 
      } 
      return false; 
  } 

  // Returns true if the graph contains a cycle, else false. 
  bool Graph::isCyclic() 
  { 
      // Mark all the vertices as not visited and not part of recursion 
      // stack 
      bool *visited = new bool[V]; 
      for (int i = 0; i < V; i++) 
          visited[i] = false; 

      // Call the recursive helper function to detect cycle in different 
      // DFS trees 
      for (int u = 0; u < V; u++) 
          if (!visited[u]) // Don't recur for u if it is already visited 
            if (isCyclicUtil(u, visited, -1)) 
               return true; 

      return false; 
  }
  
/*
  Now for Directed graph
*/
// code
  bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 

/*
  this approach is using 3 color scheme
  WHITE : Vertex is not processed yet. Initially, all vertices are WHITE.
  GRAY: Vertex is being processed (DFS for this vertex has started, but not finished 
  which means that all descendants (in DFS tree) of this vertex are not processed yet (or this vertex is in the function call stack)
  BLACK : Vertex and all its descendants are processed. While doing DFS, if an edge is encountered from current vertex to a GRAY vertex, 
  then this edge is back edge and hence there is a cycle.
  Algo
    Create a recursive function that takes the edge and color array (this can be also kept as a global variable)
    Mark the current node as GREY.
    Traverse all the adjacent nodes and if any node is marked GREY then return true as a loop is bound to exist.
    If any adjacent vertex is WHITE then call the recursive function for that node. If the function returns true. Return true.
    If no adjacent node is grey or has not returned true then mark the current Node as BLACK and return false.
*/
// code
  bool Graph::DFSUtil(int u, int color[]) 
{ 
    // GRAY :  This vertex is being processed (DFS 
    //         for this vertex has started, but not 
    //         ended (or this vertex is in function 
    //         call stack) 
    color[u] = GRAY; 
  
    // Iterate through all adjacent vertices 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // An adjacent of u 
  
        // If there is 
        if (color[v] == GRAY) 
          return true; 
  
        // If v is not processed and there is a back 
        // edge in subtree rooted with v 
        if (color[v] == WHITE && DFSUtil(v, color)) 
          return true; 
    } 
  
    // Mark this vertex as processed 
    color[u] = BLACK; 
  
    return false; 
} 
  
// Returns true if there is a cycle in graph 
bool Graph::isCyclic() 
{ 
    // Initialize color of all vertices as WHITE 
    int *color = new int[V]; 
    for (int i = 0; i < V; i++) 
        color[i] = WHITE; 
  
    // Do a DFS traversal beginning with all 
    // vertices 
    for (int i = 0; i < V; i++) 
        if (color[i] == WHITE) 
           if (DFSUtil(i, color) == true) 
              return true; 
  
    return false; 
}

/*
  
