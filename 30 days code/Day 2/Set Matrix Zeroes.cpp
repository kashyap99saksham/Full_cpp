/*
  Problem: Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
  Examples:
      [
        [1,1,1],
        [1,0,1],
        [1,1,1]
      ]
      Output: 
      [
        [1,0,1],
        [0,0,0],
        [1,0,1]
      ]
     Input: 
      [
        [0,1,2,0],
        [3,4,5,2],
        [1,3,1,5]
      ]
      Output: 
      [
        [0,0,0,0],
        [0,4,5,0],
        [0,3,1,0]
      ]
    Constraint: 
        1. A straight forward solution using O(mn) space is probably a bad idea.
        2. A simple improvement uses O(m + n) space, but still not the best solution.
        3. Could you devise a constant space solution?
*/

//Code

      void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool iscol = false;
        
        for(int i = 0; i<m; i++){
            if(matrix[i][0] == 0)
                iscol = true;
            for(int j = 1; j<n; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i<m; i++)
            for(int j = 1; j<n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if(!matrix[0][0])
            for(int i = 0; i<n; i++)
                matrix[0][i] = 0;
        if(iscol){
            for(int i = 0; i<m; i++)
                matrix[i][0] = 0;
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }   
