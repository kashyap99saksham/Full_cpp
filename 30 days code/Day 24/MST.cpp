/*
  Minimum spanning tree or minimum weight spanning tree for a weighted, connected and undirected graph 
  is a spanning tree with weight less than or equal to the weight of every other spanning tree. 
  The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.
  A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.
*/
/*
  Kruskals algorithm to find mst
  1. Sort all the edges in non-decreasing order of their weight.
  2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
  3. Repeat step#2 until there are (V-1) edges in the spanning tree.
*/
// Code
  int find(subset subsets[], int i)  
{  
    // find root and make root as parent of i  
    // (path compression)  
    if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}  
  
// A function that does union of two sets of x and y  
// (uses union by rank)  
void Union(subset subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);  
  
    // Attach smaller rank tree under root of high  
    // rank tree (Union by Rank)  
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  
  
    // If ranks are same, then make one as root and  
    // increment its rank by one  
    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}  
  
// Compare two edges according to their weights.  
// Used in qsort() for sorting an array of edges  
int myComp(const void* a, const void* b)  
{  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->weight > b1->weight;  
}  
  
// The main function to construct MST using Kruskal's algorithm  
void KruskalMST(Graph* graph)  
{  
    int V = graph->V;  
    Edge result[V]; // Tnis will store the resultant MST  
    int e = 0; // An index variable, used for result[]  
    int i = 0; // An index variable, used for sorted edges  
  
    // Step 1: Sort all the edges in non-decreasing  
    // order of their weight. If we are not allowed to  
    // change the given graph, we can create a copy of  
    // array of edges  
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);  
  
    // Allocate memory for creating V ssubsets  
    subset *subsets = new subset[( V * sizeof(subset) )];  
  
    // Create V subsets with single elements  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  
  
    // Number of edges to be taken is equal to V-1  
    while (e < V - 1 && i < graph->E)  
    {  
        // Step 2: Pick the smallest edge. And increment  
        // the index for next iteration  
        Edge next_edge = graph->edge[i++];  
  
        int x = find(subsets, next_edge.src);  
        int y = find(subsets, next_edge.dest);  
  
        // If including this edge does't cause cycle,  
        // include it in result and increment the index  
        // of result for next edge  
        if (x != y)  
        {  
            result[e++] = next_edge;  
            Union(subsets, x, y);  
        }  
        // Else discard the next_edge  
    }  
  
    // print the contents of result[] to display the  
    // built MST  
    cout<<"Following are the edges in the constructed MST\n";  
    for (i = 0; i < e; ++i)  
        cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;  
    return;  
}  
//  Cycle is detected using union find algo

/*
  Prims algorithm
  1) Create a set mstSet that keeps track of vertices already included in MST. 
  2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first. 
  3) While mstSet doesn’t include all vertices 
  ….a) Pick a vertex u which is not there in mstSet and has minimum key value. 
  ….b) Include u to mstSet. 
  ….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. 
       For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v
       The idea of using key values is to pick the minimum weight edge from cut. The key values are used only for vertices which are not yet included in MST, 
       the key value for these vertices indicate the minimum weight edges connecting them to the set of vertices included in MST. 
       
*/

// code
  int minKey(int key[], bool mstSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
 
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
 
    return min_index; 
} 
 
// A utility function to print the 
// constructed MST stored in parent[] 
void printMST(int parent[], int graph[V][V]) 
{ 
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 
 
// Function to construct and print MST for 
// a graph represented using adjacency 
// matrix representation 
void primMST(int graph[V][V]) 
{ 
    // Array to store constructed MST 
    int parent[V]; 
     
    // Key values used to pick minimum weight edge in cut 
    int key[V]; 
     
    // To represent set of vertices included in MST 
    bool mstSet[V]; 
 
    // Initialize all keys as INFINITE 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
 
    // Always include first 1st vertex in MST. 
    // Make key 0 so that this vertex is picked as first vertex. 
    key[0] = 0; 
    parent[0] = -1; // First node is always root of MST 
 
    // The MST will have V vertices 
    for (int count = 0; count < V - 1; count++)
    { 
        // Pick the minimum key vertex from the 
        // set of vertices not yet included in MST 
        int u = minKey(key, mstSet); 
 
        // Add the picked vertex to the MST Set 
        mstSet[u] = true; 
 
        // Update key value and parent index of 
        // the adjacent vertices of the picked vertex. 
        // Consider only those vertices which are not 
        // yet included in MST 
        for (int v = 0; v < V; v++) 
 
            // graph[u][v] is non zero only for adjacent vertices of m 
            // mstSet[v] is false for vertices not yet included in MST 
            // Update the key only if graph[u][v] is smaller than key[v] 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
 
    // print the constructed MST 
    printMST(parent, graph); 
} 
