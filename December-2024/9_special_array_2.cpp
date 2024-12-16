// 3152. Special Array II

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> cumSum(n, 0);

        for(int i=1; i<n; i++){
            if((nums[i]&1) == (nums[i-1]&1)) cumSum[i] = cumSum[i-1] + 1;
            else cumSum[i] = cumSum[i-1];
        }

        vector<bool> ans;
        for(int i=0; i<m; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            if(cumSum[end] - cumSum[start] == 0) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};