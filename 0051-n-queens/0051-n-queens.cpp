class Solution {
public:
    // This solution is without using isSafe function...
    void Queen(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& left, vector<int>& upperDiagonal, vector<int>& lowerDiagonal){
        // Base case: 
        if(col == board.size()){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < board.size(); row++){
            if(left[row] == 0 && upperDiagonal[(n-1) + (col - row)] == 0 && lowerDiagonal[row + col] == 0){
                // it is now safe to enter the queen
                board[row][col] = 'Q';
                left[row] = 1;
                upperDiagonal[(n-1) + (col - row)] = 1;
                lowerDiagonal[row + col] = 1;
                Queen(col + 1, n, board, ans, left, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';
                left[row] = 0;
                upperDiagonal[(n-1) + (col - row)] = 0;
                lowerDiagonal[row + col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.'); // means n times ......
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        // created the chess board with '.'

        // three hash arrays
        vector<int> left(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 

        Queen(0, board.size(), board, ans, left, upperDiagonal, lowerDiagonal);

        return ans;

    }
};