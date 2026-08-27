#include<iostream>
#include<vector>
using namespace std;

void solve(int row, int col, vector<vector<int>>& maze, int n, vector<string>& ans, string path, vector<vector<int>>& vis){
    // base case
    if(row == n - 1 && col == n - 1){
        ans.push_back(path);
        return;
    }

    // Lexicographically DLRU
    // Down
    if(row + 1 < n && !vis[row + 1][col] && maze[row + 1][col] == 1){
        vis[row][col] = 1;
        // or we can also do path.push_back('D') and use string& path in the function arguments
        solve(row + 1, col, maze, n, ans, path + 'D', vis);
        vis[row][col] = 0;
    }
    // Left
    if(col - 1 >= 0 && !vis[row][col - 1] && maze[row][col - 1] == 1){
        vis[row][col] = 1;
        solve(row, col - 1, maze, n, ans, path + 'L', vis);
        vis[row][col] = 0;
    }
    // Right
    if(col + 1 < n && !vis[row][col + 1] && maze[row][col + 1] == 1){
        vis[row][col] = 1;
        solve(row, col + 1, maze, n, ans, path + 'R', vis);
        vis[row][col] = 0;
    }
    // Up
    if(row - 1 >= 0 && !vis[row - 1][col] && maze[row - 1][col] == 1){
        vis[row][col] = 1;
        solve(row - 1, col, maze, n, ans, path + 'U', vis);
        vis[row][col] = 0;
    }
}


vector<string> findPath(vector<vector<int>>& maze, int n){
    vector<string> ans;
    // making the visited array
    vector<vector<int>> vis(n, vector<int>(n, 0));
    string path;
    if(maze[0][0] == 1) solve(0, 0, maze, n, ans, path, vis); // if it is zero then path is not possible
    return ans;
}
int main(){
    vector<vector<int>> maze = {
        {1, 0, 0, 1},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 1}
    };

    vector<string> ans = findPath(maze, maze.size());
    for(auto val : ans){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}