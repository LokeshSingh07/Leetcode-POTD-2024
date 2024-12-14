// 2257. Count Unguarded Cells in the Grid

class Solution {
public:
    void markVisited(int m, int n, vector<vector<int>> &grid, vector<vector<int>>& guards, vector<vector<int>>& walls, int i, int j){
        // mark visited the entire row and column

        // up
        for(int dx=i-1; dx>=0; dx--){
            if(grid[dx][j] == 2 || grid[dx][j] == 3) break;
            grid[dx][j] = 1;
        }

        // down
        for(int dx=i+1; dx<m; dx++){
            if(grid[dx][j] == 2 || grid[dx][j] == 3) break;
            grid[dx][j] = 1;
        }
            
        // left
        for(int dy=j-1; dy>=0; dy--){
            if(grid[i][dy] == 2 || grid[i][dy] == 3) break;
            grid[i][dy] = 1;
        }

        // right
        for(int dy=j+1; dy<n; dy++){
            if(grid[i][dy] == 2 || grid[i][dy] == 3) break;
            grid[i][dy] = 1;
        }

    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // 0 -> unguarded
        // 1 -> guarded
        // 2 -> W
        // 3 -> G

        // marks walls
        for(int i=0; i<walls.size(); i++){
            grid[walls[i][0]][walls[i][1]] = 2;
        }

        // marks guard
        for(int i=0; i<guards.size(); i++){
            grid[guards[i][0]][guards[i][1]] = 3;
        }

        for(int i=0; i<guards.size(); i++){
            markVisited(m, n, grid, guards, walls, guards[i][0], guards[i][1]);
        }


        // count the unguarded cells
        int unguarded = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) unguarded++;
            }
        }

        return unguarded;
    }
};