/*
  A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) 
  either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, 
  or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.
  A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. 
  Note that it is possible to color a cycle graph with even cycle using two colors. 
  It is not possible to color a cycle graph with odd cycle using two colors.
  Algorithm to check if a graph is Bipartite:
    One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem.
    Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS).
    1. Assign RED color to the source vertex (putting into set U).
    2. Color all the neighbors with BLUE color (putting into set V).
    3. Color all neighbor’s neighbor with RED color (putting into set U).
    4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
    5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, 
    then the graph cannot be colored with 2 vertices (or graph is not Bipartite)
    
*/
// Code
  bool isBipartite(int G[][V], int src) 
{ 
    // Create a color array to store colors  
    // assigned to all veritces. Vertex  
    // number is used as index in this array.  
    // The value '-1' of colorArr[i]  
    // is used to indicate that no color  
    // is assigned to vertex 'i'. The value 1  
    // is used to indicate first color  
    // is assigned and value 0 indicates  
    // second color is assigned. 
    int colorArr[V]; 
    for (int i = 0; i < V; ++i) 
        colorArr[i] = -1; 
  
    // Assign first color to source 
    colorArr[src] = 1; 
  
    // Create a queue (FIFO) of vertex  
    // numbers and enqueue source vertex 
    // for BFS traversal 
    queue <int> q; 
    q.push(src); 
  
    // Run while there are vertices  
    // in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
        int u = q.front(); 
        q.pop(); 
  
        // Return false if there is a self-loop  
        if (G[u][u] == 1) 
        return false;  
  
        // Find all non-colored adjacent vertices 
        for (int v = 0; v < V; ++v) 
        { 
            // An edge from u to v exists and  
            // destination v is not colored 
            if (G[u][v] && colorArr[v] == -1) 
            { 
                // Assign alternate color to this adjacent v of u 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            // An edge from u to v exists and destination  
            // v is colored with same color as u 
            else if (G[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    } 
  
    // If we reach here, then all adjacent   
    // vertices can be colored with alternate color 
    return true; 
} 

/* 
  The above algorithm works only if the graph is connected. In above code, we always start with source 0 and assume that vertices are visited from it. 
  One important observation is a graph with no edges is also Bipiartite. Note that the Bipartite condition says all edges should be from one set to another.
  We can extend the above code to handle cases when a graph is not connected. The idea is repeatedly call above method for all not yet visited vertices.
*/
// code
  bool isBipartiteUtil(int G[][V], int src, int colorArr[]) 
{ 
    colorArr[src] = 1; 
  
    // Create a queue (FIFO) of vertex numbers a 
    // nd enqueue source vertex for BFS traversal 
    queue <int> q; 
    q.push(src); 
  
    // Run while there are vertices in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
        int u = q.front(); 
        q.pop(); 
  
        // Return false if there is a self-loop  
        if (G[u][u] == 1) 
        return false;  
  
        // Find all non-colored adjacent vertices 
        for (int v = 0; v < V; ++v) 
        { 
            // An edge from u to v exists and 
            // destination v is not colored 
            if (G[u][v] && colorArr[v] == -1) 
            { 
                // Assign alternate color to this 
                // adjacent v of u 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            // An edge from u to v exists and destination 
            // v is colored with same color as u 
            else if (G[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    } 
  
    // If we reach here, then all adjacent vertices can 
    // be colored with alternate color 
    return true; 
} 
  
// Returns true if G[][] is Bipartite, else false 
bool isBipartite(int G[][V]) 
{ 
    // Create a color array to store colors assigned to all 
    // veritces. Vertex/ number is used as index in this 
    // array. The value '-1' of colorArr[i] is used to 
    // ndicate that no color is assigned to vertex 'i'. 
    // The value 1 is used to indicate first color is 
    // assigned and value 0 indicates second color is 
    // assigned. 
    int colorArr[V]; 
    for (int i = 0; i < V; ++i) 
        colorArr[i] = -1; 
  
    // This code is to handle disconnected graoh 
    for (int i = 0; i < V; i++) 
    if (colorArr[i] == -1) 
        if (isBipartiteUtil(G, i, colorArr) == false) 
        return false; 
  
    return true; 
} 

// code using DFS
  bool isBipartite(vector<int> adj[], int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
  
    for (int u : adj[v]) { 
  
        // if vertex u is not explored before 
        if (visited[u] == false) { 
  
            // mark present vertic as visited 
            visited[u] = true; 
  
            // mark its color opposite to its parent 
            color[u] = !color[v]; 
  
            // if the subtree rooted at vertex v is not bipartite 
            if (!isBipartite(adj, u, visited, color)) 
                return false; 
        } 
  
        // if two adjacent are colored with same color then 
        // the graph is not bipartite 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
}
