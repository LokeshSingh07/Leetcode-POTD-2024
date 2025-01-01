// 2466. Count Ways To Build Good Strings

class Solution {
public:
    int Z, O;
    int L, H;
    const int M = 1e9+7;

    int solve(int l, vector<int> &dp){
        if(l > H) return 0;
        if(dp[l] != -1) return dp[l];
        
        bool addOne = false;
        if(l>=L && l <= H){
            addOne = true;
        }

        int append_zero = solve(l + Z, dp);
        int append_one = solve(l + O, dp);

        return dp[l] = (addOne + append_zero + append_one)%M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        L = low;
        H = high;
        Z = zero;
        O = one;

        vector<int> dp(high+1, -1);
        return solve(0, dp);
    }
};