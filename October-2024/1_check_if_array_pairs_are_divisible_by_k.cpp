// 1497. Check If Array Pairs Are Divisible by k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k);  // store the count of remainder

        for(auto it: arr){
            int rem = ((it%k) + k) % k;     // hhandle for -ve rem
            mp[rem]++;
        }

        // catch
        if(mp[0]&1) return false;

        for(int i=1; i<=k/2; i++){
            int counterHalf = k - i;
            if(mp[counterHalf] != mp[i]) return false;
        }

        return true;
    }
};