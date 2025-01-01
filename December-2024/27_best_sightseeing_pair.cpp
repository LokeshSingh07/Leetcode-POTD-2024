// 1014. Best Sightseeing Pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> ans(n, 0);
        int maxVal = INT_MIN;

        ans[0] = values[0];
        for(int i=1; i<n; i++){
            ans[i] = max(ans[i-1], values[i]+i);
        }

        for(int j=1; j<n; j++){
            maxVal = max(maxVal, ans[j-1]+values[j]-j);
        }

        return maxVal;
    }
};