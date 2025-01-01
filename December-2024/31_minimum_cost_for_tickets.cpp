// 983. Minimum Cost For Tickets

class Solution {
public:
    int solveMemo(vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
        if(index >= days.size()) return 0;

        if(dp[index] != -1) return dp[index];

        // 1 day pass
        int cost1 = costs[0] + solveMemo(days, costs, index+1, dp);

        // 7 day pass
        int passEndDay = days[index] + 7 - 1;
        int j = index;
        while(j < days.size() && days[j] <= passEndDay) j++;
        int cost7 = costs[1] + solveMemo(days, costs, j, dp);    // catch

        // 30 days pass
        passEndDay = days[index] + 30 - 1;
        j = index;
        while(j < days.size() && days[j] <= passEndDay) j++;
        int cost30 = costs[2] + solveMemo(days, costs, j, dp);   

        return dp[index] = min(cost1, min(cost7, cost30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solveMemo(days, costs, 0, dp);
    }
};