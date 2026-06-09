class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Optimal 
        // Transpose the matrix
        int n = matrix.size();
        // n x n matrix
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // now we have to reverse the row
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n / 2; j++){
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }

            // or reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};