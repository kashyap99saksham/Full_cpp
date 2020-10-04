/*
  This is a variation of the standard problem: “Counting the number of connected components in an undirected graph”.
  
  The problem can be easily solved by applying DFS() on each component. In each DFS() call, a component or a sub-graph is visited. 
  We will call DFS on the next un-visited component. The number of calls to DFS() gives the number of connected components. BFS can also be used.
  A cell in 2D matrix can be connected to 8 neighbours. So, unlike standard DFS(), where we recursively call for all adjacent vertices, 
  here we can recursively call for 8 neighbours only. We keep track of the visited 1s so that they are not visited again.
  
*/
// Code
  // A function to check if a given 
// cell (row, col) can be included in DFS 
int isSafe(int M[][COL], int row, int col, 
           bool visited[][COL]) 
{ 
    // row number is in range, column 
    // number is in range and value is 1 
    // and not yet visited 
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]); 
} 
  
// A utility function to do DFS for a 
// 2D boolean matrix. It only considers 
// the 8 neighbours as adjacent vertices 
void DFS(int M[][COL], int row, int col, 
         bool visited[][COL]) 
{ 
    // These arrays are used to get 
    // row and column numbers of 8 
    // neighbours of a given cell 
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
  
    // Mark this cell as visited 
    visited[row][col] = true; 
  
    // Recur for all connected neighbours 
    for (int k = 0; k < 8; ++k) 
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited)) 
            DFS(M, row + rowNbr[k], col + colNbr[k], visited); 
} 
  
// The main function that returns 
// count of islands in a given boolean 
// 2D matrix 
int countIslands(int M[][COL]) 
{ 
    // Make a bool array to mark visited cells. 
    // Initially all cells are unvisited 
    bool visited[ROW][COL]; 
    memset(visited, 0, sizeof(visited)); 
  
    // Initialize count as 0 and 
    // travese through the all cells of 
    // given matrix 
    int count = 0; 
    for (int i = 0; i < ROW; ++i) 
        for (int j = 0; j < COL; ++j) 
  
            // If a cell with value 1 is not 
            if (M[i][j] && !visited[i][j]) { 
                // visited yet, then new island found 
                // Visit all cells in this island. 
                DFS(M, i, j, visited); 
  
                // and increment island count 
                ++count; 
            } 
  
    return count; 
} 

/*
  We can also solve the question using disjoint set data structure explained here. The idea is to consider all 1 values as individual sets. 
  Traverse the matrix and do a union of all adjacent 1 vertices. Below are detailed steps.
  Approach:
  1) Initialize result (count of islands) as 0
  2) Traverse each index of the 2D matrix.
  3) If the value at that index is 1, check all its 8 neighbours. If a neighbour is also equal to 1, take the union of the index and its neighbour.
  4) Now define an array of size row*column to store frequencies of all sets.
  5) Now traverse the matrix again.
  6) If the value at index is 1, find its set.
  7) If the frequency of the set in the above array is 0, increment the result be 1.
  
*/
// Code
  class DisjointUnionSets 
{ 
      
    vector<int> rank, parent; 
    int n; 
      
    public: 
    DisjointUnionSets(int n) 
    { 
        rank.resize(n); 
        parent.resize(n); 
        this->n = n; 
        makeSet(); 
    } 
  
    void makeSet() 
    { 
        // Initially, all elements   
        // are in their own set. 
        for (int i = 0; i < n; i++) 
            parent[i] = i; 
    } 
  
    // Finds the representative of the set  
    // that x is an element of 
    int find(int x) 
    { 
        if (parent[x] != x) 
        { 
            // if x is not the parent of itself, 
            // then x is not the representative of 
            // its set. 
            // so we recursively call Find on its parent 
            // and move i's node directly under the 
            // representative of this set 
            return find(parent[x]); 
        } 
  
        return x; 
    } 
  
    // Unites the set that includes x and the set 
    // that includes y 
    void Union(int x, int y) 
    { 
        // Find the representatives(or the root nodes) 
        // for x an y 
        int xRoot = find(x); 
        int yRoot = find(y); 
  
        // Elements are in the same set,  
        // no need to unite anything. 
        if (xRoot == yRoot) 
            return; 
  
        // If x's rank is less than y's rank 
        // Then move x under y so that  
        // depth of tree remains less 
        if (rank[xRoot] < rank[yRoot]) 
            parent[xRoot] = yRoot; 
  
        // Else if y's rank is less than x's rank 
        // Then move y under x so that depth of tree 
        // remains less 
        else if (rank[yRoot] < rank[xRoot]) 
            parent[yRoot] = xRoot; 
  
        else // Else if their ranks are the same 
        { 
            // Then move y under x (doesn't matter 
            // which one goes where) 
            parent[yRoot] = xRoot; 
  
            // And increment the result tree's 
            // rank by 1 
            rank[xRoot] = rank[xRoot] + 1; 
        } 
    } 
}; 
  
// Returns number of islands in a[][] 
int countIslands(vector<vector<int>>a) 
{ 
    int n = a.size(); 
    int m = a[0].size(); 
  
    DisjointUnionSets *dus = new DisjointUnionSets(n * m); 
  
    /* The following loop checks for its neighbours 
    and unites the indexes if both are 1. */
    for (int j = 0; j < n; j++) 
    { 
        for (int k = 0; k < m; k++) 
        { 
            // If cell is 0, nothing to do 
            if (a[j][k] == 0) 
                continue; 
  
            // Check all 8 neighbours and do a Union 
            // with neighbour's set if neighbour is 
            // also 1 
            if (j + 1 < n && a[j + 1][k] == 1) 
                dus->Union(j * (m) + k,  
                          (j + 1) * (m) + k); 
            if (j - 1 >= 0 && a[j - 1][k] == 1) 
                dus->Union(j * (m) + k,  
                          (j - 1) * (m) + k); 
            if (k + 1 < m && a[j][k + 1] == 1) 
                dus->Union(j * (m) + k,  
                          (j) * (m) + k + 1); 
            if (k - 1 >= 0 && a[j][k - 1] == 1) 
                dus->Union(j * (m) + k, 
                          (j) * (m) + k - 1); 
            if (j + 1 < n && k + 1 < m &&  
                    a[j + 1][k + 1] == 1) 
                dus->Union(j * (m) + k,  
                          (j + 1) * (m) + k + 1); 
            if (j + 1 < n && k - 1 >= 0 &&  
                    a[j + 1][k - 1] == 1) 
                dus->Union(j * m + k,  
                          (j + 1) * (m) + k - 1); 
            if (j - 1 >= 0 && k + 1 < m &&  
                     a[j - 1][k + 1] == 1) 
                dus->Union(j * m + k,  
                          (j - 1) * m + k + 1); 
            if (j - 1 >= 0 && k - 1 >= 0 &&  
                     a[j - 1][k - 1] == 1) 
                dus->Union(j * m + k,  
                          (j - 1) * m + k - 1); 
        } 
    } 
  
    // Array to note down frequency of each set 
    int *c = new int[n * m]; 
    int numberOfIslands = 0; 
    for (int j = 0; j < n; j++) 
    { 
        for (int k = 0; k < m; k++) 
        { 
            if (a[j][k] == 1) 
            { 
                int x = dus->find(j * m + k); 
  
                // If frequency of set is 0, 
                // increment numberOfIslands 
                if (c[x] == 0) 
                { 
                    numberOfIslands++; 
                    c[x]++; 
                } 
  
                else
                    c[x]++; 
            } 
        } 
    } 
    return numberOfIslands; 
} 

// code using BFS
  bool isSafe(int mat[R][C], int i, int j, 
            bool vis[R][C]) 
{ 
    return (i >= 0) && (i < R) &&  
           (j >= 0) && (j < C) &&  
           (mat[i][j] && !vis[i][j]); 
} 
  
void BFS(int mat[R][C], bool vis[R][C], 
         int si, int sj) 
{ 
  
    // These arrays are used to get row and 
    // column numbers of 8 neighbours of 
    // a given cell 
    int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
  
    // Simple BFS first step, we enqueue 
    // source and mark it as visited 
    queue<pair<int, int> > q; 
    q.push(make_pair(si, sj)); 
    vis[si][sj] = true; 
  
    // Next step of BFS. We take out 
    // items one by one from queue and 
    // enqueue their univisited adjacent 
    while (!q.empty()) { 
  
        int i = q.front().first; 
        int j = q.front().second; 
        q.pop(); 
  
        // Go through all 8 adjacent 
        for (int k = 0; k < 8; k++) { 
            if (isSafe(mat, i + row[k], 
                       j + col[k], vis)) { 
             vis[i + row[k]][j + col[k]] = true; 
             q.push(make_pair(i + row[k], j + col[k])); 
            } 
        } 
    } 
} 
  
// This function returns number islands (connected 
// components) in a graph. It simply works as  
// BFS for disconnected graph and returns count 
// of BFS calls. 
int countIslands(int mat[R][C]) 
{ 
    // Mark all cells as not visited 
    bool vis[R][C]; 
    memset(vis, 0, sizeof(vis)); 
  
    // Call BFS for every unvisited vertex 
    // Whenever we see an univisted vertex, 
    // we increment res (number of islands) 
    // also. 
    int res = 0; 
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) { 
            if (mat[i][j] && !vis[i][j]) { 
                BFS(mat, vis, i, j); 
                res++; 
            } 
        } 
    } 
  
    return res; 
} 
