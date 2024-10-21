// 2044. Count Number of Maximum Bitwise-OR Subsets

class Solution {
public:
    int solveRec(vector<int> &nums, int i, int maxOR, int currOR){
        if(i >= nums.size()){
            return (currOR == maxOR) ? 1 : 0;
        }

        // inc and exc
        int cnt = 0;
        cnt += solveRec(nums, i+1, maxOR, currOR | nums[i]);
        cnt += solveRec(nums, i+1, maxOR, currOR);

        return cnt;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int i=0; i<nums.size(); i++){
            maxOR |= nums[i];
        }
        
        return solveRec(nums, 0, maxOR, 0);
    }
};