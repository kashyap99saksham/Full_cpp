/*
  Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, 
  vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
  The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).
  
  In topological sorting, we use a temporary stack. We don’t print the vertex immediately, 
  we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. 
  Finally, print contents of stack. Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in stack.
*/

// code
  void Graph::topologicalSortUtil( 
int v, bool visited[],  
                                stack<int> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices  
// adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack  
// which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. 
// It uses recursive topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
// to store Topological 
    // Sort starting from all  
// vertices one by one 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    while (Stack.empty() == false) 
    { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
}

/*
   to print all possible topological sorting of DAG
    Initialize all vertices as unvisited.
    Now choose vertex which is unvisited and has zero indegree and decrease indegree of all those vertices by 1 (corresponding to removing edges) 
    now add this vertex to result and call the recursive function again and backtrack.
    After returning from function reset values of visited, result and indegree for enumeration of other possibilities.
    
*/
// code
  
//  Main recursive function to print all possible 
//  topological sorts 
void Graph::alltopologicalSortUtil(vector<int>& res, 
                                   bool visited[]) 
{ 
    // To indicate whether all topological are found 
    // or not 
    bool flag = false;  
  
    for (int i = 0; i < V; i++) 
    { 
        //  If indegree is 0 and not yet visited then 
        //  only choose that vertex 
        if (indegree[i] == 0 && !visited[i]) 
        { 
            //  reducing indegree of adjacent vertices 
            list<int>:: iterator j; 
            for (j = adj[i].begin(); j != adj[i].end(); j++) 
                indegree[*j]--; 
  
            //  including in result 
            res.push_back(i); 
            visited[i] = true; 
            alltopologicalSortUtil(res, visited); 
  
            // resetting visited, res and indegree for 
            // backtracking 
            visited[i] = false; 
            res.erase(res.end() - 1); 
            for (j = adj[i].begin(); j != adj[i].end(); j++) 
                indegree[*j]++; 
  
            flag = true; 
        } 
    } 
  
    //  We reach here if all vertices are visited. 
    //  So we print the solution here 
    if (!flag) 
    { 
        for (int i = 0; i < res.size(); i++) 
            cout << res[i] << " "; 
        cout << endl; 
    } 
}
