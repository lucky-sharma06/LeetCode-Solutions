class Solution {
public:
    bool searchWord(int row, int col, vector<vector<char>>& board, string& word, vector<vector<int>>& vis, int idx){
        // base case
        if(idx == word.size() - 1){
            // word found
            return true;
        }

        // UP
        if(row - 1 >= 0 && !vis[row - 1][col] && board[row - 1][col] == word[idx + 1]){
            vis[row - 1][col] = 1; 
            if(searchWord(row - 1, col, board, word, vis, idx + 1)){ return true; };
            vis[row - 1][col] = 0;
        }
        // Down
        if(row + 1 < board.size() && !vis[row + 1][col] && board[row + 1][col] == word[idx + 1]){
            vis[row + 1][col] = 1; 
            if(searchWord(row + 1, col, board, word, vis, idx + 1)){ return true; };
            vis[row + 1][col] = 0;
        }
        // Left
        if(col - 1 >= 0 && !vis[row][col - 1] && board[row][col - 1] == word[idx + 1]){
            vis[row][col - 1] = 1; 
            if(searchWord(row, col - 1, board, word, vis, idx + 1)){ return true; };
            vis[row][col - 1] = 0;
        }

        // Right
        if(col + 1 < board[0].size() && !vis[row][col + 1] && board[row][col + 1] == word[idx + 1]){
            vis[row][col + 1] = 1;
            if(searchWord(row, col + 1, board, word, vis, idx + 1)){ return true; };
            vis[row][col + 1] = 0;
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // creating a visiting array 2d
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)); // m rows, n cols mattrix initialized to 0
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                // traversing the board
                if(board[row][col] == word[0]){
                    vis[row][col] = 1;
                    if(searchWord(row, col, board, word, vis, 0)){
                        return true;
                    }
                    vis[row][col] = 0;
                }
            }
        }
        return false;
        
    }
};