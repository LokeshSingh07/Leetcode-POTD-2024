// 1760. Minimum Limit of Balls in a Bag

class Solution {
public:
    bool isPossible(vector<int> &nums, int maxOpn, int mid){
        int totalOpn = 0;

        for(auto &num: nums){
            int opn = num/mid;
            if(num % mid == 0) opn -= 1;
            totalOpn += opn;
        }

        return (totalOpn <= maxOpn);
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1;
        int e = *max_element(begin(nums), end(nums));
        int ans = e;

        while(s <= e){
            int mid = s+(e-s)/2;
            if(isPossible(nums, maxOperations, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return ans;
    }
};