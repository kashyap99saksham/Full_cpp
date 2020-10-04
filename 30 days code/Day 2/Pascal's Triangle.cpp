/*
  Problem  :  Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
              1
              1 1
              1 2 1
              1 3 3 1
              1 4 6 4 1

              In Pascal's triangle, each number is the sum of the two numbers directly above it.
 */
 
// Code

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if(!numRows)
            return triangle;
        vector<int> temp;
        temp.push_back(1);
        triangle.push_back(temp);
        if(numRows == 1) return triangle;
        for(int row = 1; row<numRows; row++){
            vector<int> r;
            for(int i = 0; i<triangle[row-1].size()+1; i++){
                if(i == 0 || i == triangle[row-1].size())
                    r.push_back(1);
                else{
                    r.push_back(triangle[row-1][i-1] + triangle[row-1][i]);
                }
            }
            triangle.push_back(r);
        }
        return triangle;
    }
