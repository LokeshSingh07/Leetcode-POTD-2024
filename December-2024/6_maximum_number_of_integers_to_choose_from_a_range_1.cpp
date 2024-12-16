// 2554. Maximum Number of Integers to Choose From a Range I

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum=0,cnt=0;

        for(int i=1; i<=n; i++){
            if(find(begin(banned), end(banned), i) != end(banned)) continue;
            
            sum += i;
            cnt++;
            if(sum > maxSum){
                sum -= i;
                cnt--;
            }
        }

        return cnt;
    }
};