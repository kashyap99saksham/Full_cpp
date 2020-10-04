 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)return false;

        int n = matrix[0].size();
        int i = n-1, j = 0;
        while(j<m && i>-1){
            if(target == matrix[j][i])
                return true;
            else if(matrix[j][i]>target)
                i--;
            else
                j++;
        }
        return false;
    }
