class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //  m is row and n is col
        // col -> matrix[0][...]
        // row -> matrix[...][0]
        int col0 = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j == 0){
                        col0 = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        // marking is complete...
        // now traverse without the 0th row and 0th col
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        // till now except 0 row and 0 col everything is done
        // since col is dependent on row, so we will do col first

        // col is done
        for(int j = 1; j < n; j++){
            if(matrix[0][0] == 0){
                matrix[0][j] = 0;
            }
        }

        // now about row
        for(int i = 0; i < m; i++){
            if(col0 == 0){
                matrix[i][0] = 0;
            }
        }

    
        return;
    }
};