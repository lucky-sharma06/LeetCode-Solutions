class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board){
        // check for the left upper diagonal
        int r = row; 
        int c = col;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = r;
        col = c;
        // check for the left columns
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = r;
        col = c;
        // check for the left lower diagonal
        while(col >= 0 && row < n){
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void Queen(int col, vector<string>& board, vector<vector<string>>& ans){
        // Base case: 
        if(col == board.size()){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < board.size(); row++){
            if(isSafe(row, col, board.size(), board)){
                // it is safe to put the queen
                board[row][col] = 'Q';
                Queen(col + 1, board, ans);
                board[row][col] = '.';
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
        int row = 0;
        int col = 0;
        Queen(col, board, ans);

        return ans;

    }
};