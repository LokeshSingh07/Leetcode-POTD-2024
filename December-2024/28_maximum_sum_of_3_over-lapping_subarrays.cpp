// 689. Maximum Sum of 3 Non-Overlapping Subarrays

class Solution {
public:
    int dp[20001][4];

    int Helper(vector<int>&subArray, int k, int idx, int count){
        if(count == 0) return 0;
        if(idx >= subArray.size()) return INT_MIN;

        if(dp[idx][count] != -1) return dp[idx][count];

        int take = subArray[idx] + Helper(subArray, k, idx+k, count-1);
        int not_take = Helper(subArray, k, idx+1, count);

        return dp[idx][count] = max(take, not_take);
    }


    void solveRec(vector<int> &subArray, int k, int idx, int count, vector<int> &result){
        if(count == 0) return; 
        if(idx >= subArray.size()) return;

        int take = subArray[idx] + Helper(subArray, k, idx+k, count-1);
        int not_take = Helper(subArray, k, idx+1, count);

        if(take >= not_take){
            result.push_back(idx);
            solveRec(subArray, k, idx+k, count-1, result);
        }
        else{
            solveRec(subArray, k, idx+1, count, result);
        }

    }


    void subarraySum(vector<int>&nums, int k, vector<int> &subArray){
        int n = nums.size();
        int i=0, j=0;
        int sum = 0;

        while(j<n){
            sum += nums[j];

            if(j-i+1 == k){
                subArray.push_back(sum);
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));

        // create subarray sum of size k starting from index i  
        vector<int> subArray;
        subarraySum(nums, k, subArray);

        // recursion 
        int i = 0;
        int maxCount = 3;
        vector<int> result;
        solveRec(subArray, k, i, maxCount, result);

        return result;
    }
};