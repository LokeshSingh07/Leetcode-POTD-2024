// 2762. Continuous Subarrays

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        map<int,int> mp;
        int i=0, j=0;

        while(j < n){
            mp[nums[j]]++;

            // check out of range subarray
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2){
                // remove the nums[i] from map
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            count += j-i+1;
            j++;
        }

        return count;
    }
};