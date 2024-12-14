// 2290. Minimum Obstacle Removal to Reach Corner

class Solution {
public:
    #define P pair<int,pair<int,int>>
    vector<vector<int>> directions = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));     // distance
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0,0}});        // {wt, {i, j}}
        result[0][0] = 0;

        while(!pq.empty()){
            P curr = pq.top();
            pq.pop();
            int d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            // tarverse its nbr
            for(auto dir : directions){
                int newx = x + dir[0];
                int newy = y + dir[1];

                if(newx < 0 || newx >= m || newy < 0 || newy >= n) continue;

                int wt = grid[x][y];

                if(d+wt < result[newx][newy]){
                    result[newx][newy] = d+wt;
                    pq.push({d+wt, {newx, newy}});

                }
            }
        }

        return result[m-1][n-1];
    }
};