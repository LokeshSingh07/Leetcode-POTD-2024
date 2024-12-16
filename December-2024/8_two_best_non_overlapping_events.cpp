// 2054. Two Best Non-Overlapping Events

class Solution {
public:
    int n;
    int BS(vector<vector<int>>& events, int endTime){
        int s = 0;
        int e = events.size()-1;
        int ans = n;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(events[mid][0] > endTime){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>& events, int i, int count, vector<vector<int>> &dp){
        if(count == 2 || i>= n) return 0;
        if(dp[i][count] != -1) return dp[i][count];

        int nextValidIndex = BS(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidIndex, count+1,dp);
        int notTake = 0 + solve(events, i+1, count,dp);

        return dp[i][count] = max(take, notTake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(begin(events), end(events));

        vector<vector<int>> dp(n, vector<int>(3,-1));
        int count = 0;
        return solve(events, 0, count, dp);
    }
};