// Find Missing Observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum  = 0;

        int rollSum = accumulate(rolls.begin(), rolls.end(), 0);

        sum = (mean * (m+n)) - rollSum;

        // not possible wala case
        if(sum > n*6 || sum<n)           // negative wala case 
            return {};

        int rem = sum % n;
        int dig = sum / n;
        vector<int> ans(n, dig);

        for(int i=0; i<rem; i++){
            ans[i]++;
        }

        return ans;
    }
};