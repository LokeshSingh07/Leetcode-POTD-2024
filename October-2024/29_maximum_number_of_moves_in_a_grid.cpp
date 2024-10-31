// 2684. Maximum Number of Moves in a Grid

class Solution {
public:
    int m, n;
    int DFS(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];

        int moves = 0;
        int direction[3] = {-1, 0, 1};
        for(int dir: direction){
            int newR = i+dir;
            int newC = j+1;
            if(newR >= 0 && newR < m && newC>=0 && newC < n && grid[newR][newC] > grid[i][j]){
                moves = max(moves, 1+DFS(newR, newC, grid, dp));
            }
        }
        return dp[i][j] = moves;
    }


    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0; i<m; i++){
            result = max(result, DFS(i, 0, grid, dp));
        }

        return result;
    }
};