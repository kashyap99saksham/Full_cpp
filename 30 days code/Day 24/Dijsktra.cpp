/*
  Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph
  it is a greedy algo so it always try to find minimum from current
  1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree, i.e., 
     whose minimum distance from source is calculated and finalized. Initially, this set is empty.
  2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. 
     Assign distance value as 0 for the source vertex so that it is picked first.
  3) While sptSet doesn’t include all vertices
  ….a) Pick a vertex u which is not there in sptSet and has minimum distance value.
  ….b) Include u to sptSet.
  ….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. 
       For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, 
       then update the distance value of v.
*/
//  code
  int minDistance(int dist[], bool sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
// A utility function to print the constructed distance array 
void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    // print the constructed distance array 
    printSolution(dist); 
} 
/*
  Notes:
  1) The code calculates shortest distance, but doesn’t calculate the path information. We can create a parent array, 
     update the parent array when distance is updated (like prim’s implementation) and use it show the shortest path from source to different vertices.
  2) The code is for undirected graph, same dijkstra function can be used for directed graphs also.
  3) The code finds shortest distances from source to all vertices. If we are interested only in shortest distance from the source to a single target, 
     we can break the for the loop when the picked minimum distance vertex is equal to target (Step 3.a of the algorithm).
  4) Time Complexity of the implementation is O(V^2). If the input graph is represented using adjacency list, 
     it can be reduced to O(E log V) with the help of binary heap. Please see
     Dijkstra’s Algorithm for Adjacency List Representation for more details.
  5) Dijkstra’s algorithm doesn’t work for graphs with negative weight edges. 
     For graphs with negative weight edges, Bellman–Ford algorithm can be used, we will soon be discussing it as a separate post.
*/
/*  
  To print path The idea is to create a separate array parent[]. Value of parent[v] for a vertex v stores parent vertex of v in shortest path tree. 
  Parent of root (or source vertex) is -1. Whenever we find shorter path through a vertex u, we make u as parent of current vertex.
  Once we have parent array constructed, we can print path using below recursive function.
*/
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}
// code using priority queue
  void Graph::shortestPath(int src) 
{ 
    // Create a set to store vertices that are being 
    // prerocessed 
    set< pair<int, int> > setds; 
  
    // Create a vector for distances and initialize all 
    // distances as infinite (INF) 
    vector<int> dist(V, INF); 
  
    // Insert source itself in Set and initialize its 
    // distance as 0. 
    setds.insert(make_pair(0, src)); 
    dist[src] = 0; 
  
    /* Looping till all shortest distance are finalized 
       then setds will become empty */
    while (!setds.empty()) 
    { 
        // The first vertex in Set is the minimum distance 
        // vertex, extract it from set. 
        pair<int, int> tmp = *(setds.begin()); 
        setds.erase(setds.begin()); 
  
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = tmp.second; 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If there is shorter path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                /*  If distance of v is not INF then it must be in 
                    our set, so removing it and inserting again 
                    with updated less distance.   
                    Note : We extract only those vertices from Set 
                    for which distance is finalized. So for them,  
                    we would never reach here.  */
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
  
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // Print shortest distances stored in dist[] 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
}
