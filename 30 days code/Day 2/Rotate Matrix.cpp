/*
  You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
  Note: You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

  Example 1:
      Given input matrix =  [[1,2,3],[4,5,6],[7,8,9]],
      output:               [[7,4,1],[8,5,2],[9,6,3]]
  Example 2:
      Given input matrix =  [[ 5, 1, 9,11],[ 2, 4, 8,10],[13, 3, 6, 7],[15,14,12,16]], 
      outpurt:              [[15,13, 2, 5],[14, 3, 4, 1],[12, 6, 8, 9],[16, 7,10,11]]

*/

//code

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int x = 0; x<n/2; x++){
            for(int y = x; y<n-x-1; y++){
                int temp = matrix[x][y];
                matrix[x][y] = matrix[n-y-1][x];
                matrix[n-y-1][x] = matrix[n-x-1][n-y-1];
                matrix[n-x-1][n-y-1] = matrix[y][n-x-1];
                matrix[y][n-x-1] = temp;
            }
        }
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                cout<<matrix[i][j];
}

