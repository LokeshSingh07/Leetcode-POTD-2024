// 1671. Minimum Number of Removals to Make Mountain Array

class Solution {
public:
    void solveRec(vector<int>& nums, vector<int>& lis){
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]) 
                    lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        // calculate LIS and LDS
        solveRec(nums, LIS);
        reverse(nums.begin(), nums.end());
        solveRec(nums, LDS);
        reverse(LDS.begin(), LDS.end());

        // find minimum removal
        int miniRemoval = n;
        for(int i=0; i<n; i++){
            if(LIS[i] > 1 && LDS[i] > 1){
                miniRemoval = min(miniRemoval, (n - LIS[i] - LDS[i] + 1));
            }
        }

        return miniRemoval;;
    }
};