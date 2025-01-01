// 494. Target Sum

class Solution {
public:
    int ans = 0;
    void solveRec(vector<int> &nums, int index, int sum, int target){
        if(index >= nums.size()){
            if(sum == target) ans++;
            return;
        }

        solveRec(nums, index+1, sum + nums[index], target);
        solveRec(nums, index+1, sum - nums[index], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        solveRec(nums, 0, 0, target);
        return ans;
    }
};