// 2593. Find Score of an Array After Marking All Elements

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> vec(n);

        // make vec array {val, idx}
        for(int i=0; i<n; i++){
            vec[i] = {nums[i], i};
        }

        sort(vec.begin(), vec.end());

        vector<bool> visited(n, false);
        long long score = 0;
        for(int i=0; i<n; i++){
            long long val = vec[i].first;
            int idx = vec[i].second;

            if(!visited[idx]){
                visited[idx] = true;
                score += val;

                if(idx-1 >= 0 && !visited[idx-1]){
                    visited[idx-1] = true;
                }
                if(idx+1 < n && !visited[idx+1]){
                    visited[idx+1] = true;
                }
            } 
        }

        return score;
    }
};