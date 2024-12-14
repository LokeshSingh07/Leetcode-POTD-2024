// 862. Shortest Subarray with Sum at Least K

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> cSum(n);
        deque<int> deq;
        long long sum=0, res=INT_MAX;
        long long j=0;


        while(j < n){
            sum+=nums[j];
            cSum[j] = sum;
            if(cSum[j] >= k){
                res = min(res, j+1);
            }

            // shrink the window
            while(!deq.empty() && (cSum[j] - cSum[deq.front()] >= k)){
                res = min(res, j-deq.front());
                deq.pop_front();
            }

            // monotonic inc dequeu
            while(!deq.empty() && cSum[j] <= cSum[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(j);
            j++;
        }

        return res==INT_MAX ? -1 : res;
    }
};