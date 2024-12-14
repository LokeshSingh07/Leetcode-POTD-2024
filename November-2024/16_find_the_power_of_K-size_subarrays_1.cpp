// 3254. Find the Power of K-Size Subarrays I

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n-k+1; i++){
            int cnt=k, temp=i;
            bool flag = true;
            while(cnt > 1){
                if(nums[temp]+1 != nums[temp+1]){
                    flag = false;
                    break;
                }
                temp++;
                cnt--;
            }

            flag ? ans.push_back(nums[temp]) : ans.push_back(-1);
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1, -1);
        int cnt=1;

        // process first window
        for(int i=1; i<k; i++){
            if(nums[i] == nums[i-1]+1) cnt++;
            else  cnt = 1;
        }

        if(cnt == k) ans[0] = nums[k-1];

        // process remaining window 
        int i=1;
        int j=k;
        
        while(j < n){
            if(nums[j-1]+1 == nums[j]) cnt++;
            else cnt = 1;

            if(cnt >= k) ans[i] = nums[j];
            i++;
            j++;
        }

        return ans;
    }
};