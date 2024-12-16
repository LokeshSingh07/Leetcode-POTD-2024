// 2779. Maximum Beauty of an Array After Applying Operation

class Solution {
public:
    #define P pair<int,int>
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<P> intervals(n);

        // step1: create intervals -> {start,end}
        for(int i=0; i<n; i++){
            intervals[i] = {nums[i]-k, nums[i]+k};
        }

        // step2: sort based on starting time
        sort(begin(intervals), end(intervals));

        // step3:
        queue<int> q;   // for checking the overlapping region
        int maxBeauty = INT_MIN;
        for(auto interval: intervals){
            while(!q.empty() && q.front() < interval.first) q.pop();
            q.push(interval.second);
            maxBeauty = max(maxBeauty, (int)q.size());
        }

        return maxBeauty;
    }
};