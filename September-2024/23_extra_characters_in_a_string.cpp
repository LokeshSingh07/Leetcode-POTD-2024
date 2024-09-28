// 2707. Extra Characters in a String

class Solution {
public:
    int solveRec(string s, unordered_set<string> &st, int i, int n, vector<int> &dp){
        if(i >= n)return 0;
        
        if(dp[i] != -1) return dp[i];
        // inc  
        int inc = INT_MAX;
        for(int j=i; j<n; j++){
            string temp = s.substr(i, j-i+1);
            if(st.count(temp)){
                int recAns = solveRec(s, st, j+1, n, dp);
                inc = min(inc, recAns);
            }
        }

        // exc
        int exc = 1 + solveRec(s, st, i+1, n,  dp);

        return dp[i] = min(inc, exc);
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        unordered_set<string> st(begin(dict), end(dict));
        vector<int> dp(51, -1);
        return solveRec(s, st, 0, n, dp);
    }
};