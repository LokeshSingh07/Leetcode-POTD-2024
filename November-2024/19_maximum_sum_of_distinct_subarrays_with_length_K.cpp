// 2461. Maximum Sum of Distinct Subarrays With Length K

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long windowSum=0;
        long long maxSum=INT_MIN;
        unordered_map<int, int> st;
        int duplicate=0;
        
        // process first window
        for(int i=0; i<k; i++){
            windowSum += nums[i];
            st[nums[i]]++;
            if(st[nums[i]] == 2){       // catch
                // present
                duplicate++;
            }
        }

        if(!duplicate) maxSum = max(maxSum, windowSum);

        // process reamianing window
        int i=0;
        int j=k;
        while(j<n){
            // remove
            st[nums[i]]--;
            windowSum -= nums[i];
            if(st[nums[i]] == 1) duplicate--;       // catch
            
            // add 
            st[nums[j]]++;
            windowSum += nums[j];
            if(st[nums[j]] == 2){
                // present
                duplicate++;
            }

            // store
            if(!duplicate) maxSum = max(maxSum, windowSum);
            
            i++;j++;
        }
        
        return maxSum==INT_MIN ? 0 : maxSum;
    }
};


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0;
        long long windowSum = 0;
        unordered_set<int> st;
        int i=0, j=0;

        // sliding window
        while(j<n){
            // remove if it is already present
            while(st.count(nums[j])){
                windowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            
            // add -> not present
            windowSum += nums[j];
            st.insert(nums[j]);

            // store
            if(j-i+1 == k){
                maxSum = max(maxSum, windowSum);
                windowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }

        return maxSum;
    }
};