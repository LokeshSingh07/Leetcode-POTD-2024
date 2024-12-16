// 3264. Final Array State After K Multiplication Operations I

class Solution {
public:
    typedef pair<int,int> P;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> ans = nums;
        priority_queue<P, vector<P>, greater<P>> pq;       // {val, idx}

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }


        while(k--){
            P curr = pq.top();
            pq.pop();

            int val = curr.first;
            int index = curr.second;

            ans[index] = val*multiplier;
            pq.push({ans[index], index});
        }

        return ans;
    }
};