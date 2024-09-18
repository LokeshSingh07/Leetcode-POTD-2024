// 2419. Longest Subarray With Maximum Bitwise AND

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        int maxLen = 0;
        int currLen = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxi == nums[i]){
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            else{
                currLen = 0;
            }
        }

        return maxLen;
    }
};