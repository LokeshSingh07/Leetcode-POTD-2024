// 2463. Minimum Total Distance Traveled

class Solution {
public:
    long long solveRec(int currR, int currF, vector<int>& flatten, vector<int> &robot, vector<vector<long long>> &dp){
        if(currR >= robot.size()) return 0;
        if(currF >= flatten.size()) return 1e12;

        if(dp[currR][currF] != -1) return dp[currR][currF];

        // inc exc
        long long inc = abs(flatten[currF] - robot[currR]) + solveRec(currR+1, currF+1, flatten, robot, dp);
        long long exc = 0 + solveRec(currR, currF+1, flatten, robot, dp);

        return dp[currR][currF] = min(inc, exc);
    }


    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        vector<int> flattenFact;
        for(auto &fact: factory){
            for(int i=0; i<fact[1]; i++){
                flattenFact.push_back(fact[0]);
            }
        }

        vector<vector<long long>> dp(robot.size(), vector<long long>(flattenFact.size(), -1));

        return solveRec(0, 0, flattenFact, robot, dp);
    }
};