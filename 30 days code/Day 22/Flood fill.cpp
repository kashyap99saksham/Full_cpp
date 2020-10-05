/*
  floodFil(screen[M][N], x, y, prevC, newC)
    1) If x or y is outside the screen, then return.
    2) If color of screen[x][y] is not same as prevC, then return
    3) Recur for north, south, east and west.
        floodFillUtil(screen, x+1, y, prevC, newC);
        floodFillUtil(screen, x-1, y, prevC, newC);
        floodFillUtil(screen, x, y+1, prevC, newC);
        floodFillUtil(screen, x, y-1, prevC, newC); 
*/
// Code
  void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC) 
{ 
    // Base cases 
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (screen[x][y] != prevC) 
        return; 
    if (screen[x][y] == newC)  
        return;  
  
    // Replace the color at (x, y) 
    screen[x][y] = newC; 
  
    // Recur for north, east, south and west 
    floodFillUtil(screen, x+1, y, prevC, newC); 
    floodFillUtil(screen, x-1, y, prevC, newC); 
    floodFillUtil(screen, x, y+1, prevC, newC); 
    floodFillUtil(screen, x, y-1, prevC, newC); 
} 
  
// It mainly finds the previous color on (x, y) and 
// calls floodFillUtil() 
void floodFill(int screen[][N], int x, int y, int newC) 
{ 
    int prevC = screen[x][y]; 
    floodFillUtil(screen, x, y, prevC, newC); 
} 
