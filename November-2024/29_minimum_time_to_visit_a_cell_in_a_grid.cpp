// 2577. Minimum Time to Visit a Cell In a Grid

class Solution {
public:
    #define P pair<int,pair<int,int>>
    vector<vector<int>> directions = {{0, 1}, {0,-1}, {1,0}, {-1,0}};

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // BAse case
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        pq.push({0, {0,0}});
        result[0][0] = 0;

        while(!pq.empty()){
            P curr = pq.top();
            pq.pop();
            int time = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if(visited[x][y]) continue;
            visited[x][y] = true;

            // traverse nbr
            for(auto dir : directions){
                int newx = dir[0] + x;
                int newy = dir[1] + y;

                if(newx < 0 || newx >= m || newy < 0 || newy >= n || visited[newx][newy]) continue;

                // check 
                if(grid[newx][newy] <= time+1){
                    pq.push({time+1, {newx, newy}});
                    result[newx][newy] = time+1;
                }
                else if((grid[newx][newy] - time) % 2 == 0){
                    pq.push({grid[newx][newy]+1, {newx, newy}});
                    result[newx][newy] = grid[newx][newy] + 1;
                }
                else{
                    pq.push({grid[newx][newy], {newx, newy}});
                    result[newx][newy] = grid[newx][newy];
                }
            }
        }

        return result[m-1][n-1];
    }
};