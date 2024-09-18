// 1310. XOR Queries of a Subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();

        for(int i=0; i<n; i++){
            int XOR = 0;
            for(int idx=queries[i][0]; idx<=queries[i][1]; idx++){
                XOR ^= arr[idx];
            }
            ans.push_back(XOR);
        }
        return ans;
    }
};