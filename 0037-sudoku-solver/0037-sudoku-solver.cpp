class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // traversing the 2d sudoku
                
                if(board[i][j] == '.'){
                    // means it is empty
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board, i, j, c)){
                            // valid hai
                            board[i][j] = c;
                            if(solve(board) == true){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false; // 1 - 9 tak ek bhi ni aaya so false
                }
            }
        }
        return true; // poora iterate hogya and no false means it is correct... 
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++){
            // check for the row
            if(board[row][i] == c) return false;

            // check for the column
            if(board[i][col] == c) return false;

            // check for the 3x3 
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};