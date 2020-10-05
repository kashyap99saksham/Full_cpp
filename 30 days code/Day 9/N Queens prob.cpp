class Solution {
private:
vector<string> generateQueens(vector<int>& columnPlacements,int n)
{
    vector<string> temp;
    int total=columnPlacements.size();
    for(int i=0;i<total;i++)
    {
        string s="";
        for(int col=0;col<n;col++)
        {
            if(col==columnPlacements[i])
                s.append("Q");
            else 
                s.append(".");
        }
        temp.push_back(s);
    }
    return temp;
}
bool isSafe(vector<int>& columnPlacements)
{
    int lastPlacedQueenColumn=columnPlacements.size()-1;
    for(int i=0;i<lastPlacedQueenColumn;i++)
    {
        int absoluteColDistance=abs(columnPlacements[i]-columnPlacements[lastPlacedQueenColumn]);
        int absoluteRowDistance=lastPlacedQueenColumn-i;
        if(absoluteColDistance==0 or absoluteColDistance==absoluteRowDistance)
            return false;
    }
    return true;
}
void solveNQueensHelper(int n,int row,vector<vector<string>> &board,vector<int> &columnPlacements)
{
    if(row==n)
    {
        board.push_back(generateQueens(columnPlacements,n));
        return;
    }
    for(int col=0;col<n;col++)
    {
        columnPlacements.push_back(col);
        if(isSafe(columnPlacements))
        {
            solveNQueensHelper(n,row+1,board,columnPlacements);
        }
        //backtrack
        columnPlacements.pop_back();
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board;
        if(n==2 or n==3)
            return {};
        vector<int> columnPlacements;
        solveNQueensHelper(n,0,board,columnPlacements);
        return board;
    }
};
