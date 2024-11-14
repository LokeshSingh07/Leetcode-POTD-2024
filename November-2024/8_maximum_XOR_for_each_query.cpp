// 1829. Maximum XOR for Each Query

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans;

        // find the xor of arr
        int XOR = 0;
        for(int i=0; i<n; i++){
            XOR ^= nums[i];
        }

        // find the flip / k
        int mask = (1<<maximumBit) - 1;

        for(int i=0; i<n; i++){
            int flip = XOR ^ mask;
            ans.push_back(flip);
            
            XOR ^= nums[n-i-1];     // catch
        }

        return ans;
    }
};