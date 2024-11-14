// 3097. Shortest Subarray With OR at Least K II

class Solution {
public:
    void updateInWindow(int num, vector<int> &vec, int val){
        for(int i=0; i<32; i++){
            if((num >> i) & 1){
                vec[i] += val;
            }
        }
    }

    int getDecimalNumber(vector<int>& vec){
        int num = 0;
        for(int i=0; i<32; i++){
            if(vec[i] > 0){
                num |= (1 << i);
            }
        }
        return num;
    }


    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int result = INT_MAX;

        int i=0, j=0;
        vector<int> vec(32, 0);

        while(j < n){
            updateInWindow(nums[j], vec, 1);

            while(i<=j && getDecimalNumber(vec) >= k){
                result = min(result, j-i+1);
                updateInWindow(nums[i], vec, -1);
                i++;
            }

            j++;
        }

        return result==INT_MAX ? -1 : result;
    }
};